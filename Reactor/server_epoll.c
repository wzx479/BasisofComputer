



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <pthread.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/poll.h>


#define BUFFER_LENGTH	1024
#define POLL_SIZE		1024
#define EPOLL_SIZE		1024

int client_route(void *arg) {
	int clientfd = *(int*)arg;

	while (1) {
		char buffer[BUFFER_LENGTH] = {0};
		int ret = recv(clientfd, buffer, BUFFER_LENGTH, 0);
		if (ret < 0) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				printf("read all data\n");
			}
			//close(clientfd);
			return -1;
		} else if (ret == 0) {
			printf("disconnect \n");
			//close(clientfd);
			return 0;
		} else {
			printf("Recv:%s, %d Bytes\n", buffer, ret);
			return ret;
		}
	}
}

void* client_callback(void *arg) {
	int clientfd = *(int*)arg;

	while (1) {
		char buffer[BUFFER_LENGTH] = {0};
		int ret = recv(clientfd, buffer, BUFFER_LENGTH, 0);
		if (ret < 0) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				printf("read all data\n");
			}
			//close(clientfd);
			return NULL;
		} else if (ret == 0) {
			printf("disconnect \n");
			//close(clientfd);
			return NULL;
		} else {
			printf("Recv:%s, %d Bytes\n", buffer, ret);
			//return NULL;
		}
	}
}


int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Paramter Error\n");
		return -1;
	}
	int port = atoi(argv[1]);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		return -1;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(struct sockaddr_in));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)) < 0) {
		perror("bind");
		return 2;
	}

	if (listen(sockfd, 5) < 0) {
		perror("listen");
		return 3;
	}

#if 0

	while (1) { //c10k

		struct sockaddr_in client_addr;
		memset(&client_addr, 0, sizeof(struct sockaddr_in));
		socklen_t client_len = sizeof(client_addr);
		
		int clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
		if (clientfd <= 0) continue;

		pthread_t thread_id;
		int ret = pthread_create(&thread_id, NULL, client_callback, &clientfd);
		if (ret < 0) {
			perror("pthread_create");
			exit(1);
		}

	}
	
#elif 1

	int epoll_fd = epoll_create(EPOLL_SIZE);
	struct epoll_event ev, events[EPOLL_SIZE] = {0};

	ev.events = EPOLLIN;
	ev.data.fd = sockfd;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, &ev);

	while (1) {

		int nready = epoll_wait(epoll_fd, events, EPOLL_SIZE, -1);
		if (nready == -1) {
			printf("epoll_wait\n");
			break;
		}

		int i = 0;
		for (i = 0;i < nready;i ++) {
			if (events[i].data.fd == sockfd) {
				
				struct sockaddr_in client_addr;
				memset(&client_addr, 0, sizeof(struct sockaddr_in));
				socklen_t client_len = sizeof(client_addr);
			
				int clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
				if (clientfd <= 0) continue;
	
				char str[INET_ADDRSTRLEN] = {0};
				printf("recvived from %s at port %d, sockfd:%d, clientfd:%d\n", inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
					ntohs(client_addr.sin_port), sockfd, clientfd);

				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = clientfd;
				epoll_ctl(epoll_fd, EPOLL_CTL_ADD, clientfd, &ev);
			} else {
				int clientfd = events[i].data.fd;

				char buffer[BUFFER_LENGTH] = {0};
				int ret = recv(clientfd, buffer, BUFFER_LENGTH, 0);
				if (ret < 0) {
					if (errno == EAGAIN || errno == EWOULDBLOCK) {
						printf("read all data");
					}
					
					close(clientfd);
					
					ev.events = EPOLLIN | EPOLLET;
					ev.data.fd = clientfd;
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, clientfd, &ev);
				} else if (ret == 0) {
					printf(" disconnect %d\n", clientfd);
					
					close(clientfd);

					ev.events = EPOLLIN | EPOLLET;
					ev.data.fd = clientfd;
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, clientfd, &ev);
					
					break;
				} else {
					printf("Recv: %s, %d Bytes\n", buffer, ret);
				}
				
			}
		}

	}


#endif
	return 0;
}










