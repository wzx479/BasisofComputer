#include <stdio.h>

#include <stdlib.h>



typedef int data_t;



typedef struct linknode{

	data_t data;

	struct linknode *next;

}link_t;





link_t *creat_link()

{

	//1.申请空间

	//2.初始化

	//3.返回头结点地址

	

	link_t *head;

	head = malloc(sizeof(link_t));

	head->next = NULL;

	

	return head;

}

/*在头结点和第0个元素之间传入一个新的元素*/

int ins_head_link(link_t *head,const data_t *data)

{

	//1.申请新结点空间 写入数据

	//2.新结点指向 原来的0号结点

	//3.头结点指向 新结点 

	link_t *newnode;

	newnode = malloc(sizeof(link_t));

	newnode->data = *data;

	newnode->next = head->next;



	head->next = newnode;

	

	return 0;

}

int ins_index_link(link_t *head,int index,const data_t *data)

{

	//1.定位要插入的位置

	//2.插入一个元素

	while(index --){

		head = head->next;

		if(NULL == head)

			return -1;

	}

	ins_head_link(head,data);



	return 0;

}





int del_head_link(link_t *head)

{

	//1.备份要删除接的地址

	//2.让头接的 指向 删除接的的下一个接的

	//3.释放要删除结点

	if(NULL == head->next)

		return -1;



	link_t *temp;

	temp = head->next;

	head->next = temp->next;

	free(temp);



	return 0;

}

int del_index_link(link_t *head,int index)

{

	if(NULL == head->next)

		return -1;



	while(index --){

		head = head->next;

		if(NULL == head->next)

			return -1;

	}

	

	del_head_link(head);



	return 0;

}

int del_index_link_2(link_t *head,int index)

{



	while(index --){

		if(NULL == head->next)

			return -1;



		head = head->next;

	}



	del_head_link(head);	del_head_link(head);





	return 0;

}



link_t *locate_link(link_t *head,const data_t *data)

{

	while(NULL != head->next){

		if(*data == head->next->data)

			return head;

		head = head->next;

	}



	return NULL;

}

int change_index_link(link_t *head,int index,const data_t *newdata)

{

	if(NULL == head->next)

		return -1;



	while(index --){

		head = head->next;

		if(NULL == head->next)

			return -1;

	}

	

	head->next->data = *newdata;

	return 0;

}



int del_locate_link(link_t *head,const data_t *data)

{

	link_t *temp;

	temp = locate_link(head,data);

	if(NULL != temp)

		del_head_link(temp);



	return 0;

}



int empty_link(link_t *head)

{

	return (NULL == head->next);

}

int clean_link(link_t *head)

{

	while(0 == del_head_link(head) )

		;

	return 0;

}



int dis_link(link_t **headp)

{

	clean_link(*headp);

	free(*headp);

	

	*headp = NULL;

	return 0;

}

void print_link(link_t *head)

{

	link_t *node;



	node = head->next;

	while(NULL != node){

		printf("%d ",node->data); // (*node).data

		node = node->next;

	}

	printf("\n");



	return ;

}
