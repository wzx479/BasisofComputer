#include "adjacent.h"
#include "queue.h"
#define MAX 99

using namespace std;
int main()
{
    int status=0;
    AdjList top_info;
    struct attribute graph;
    struct linkedQueue *qQ ;
    memset (qQ,0,sizeof(struct linkedQueue));
    memset(&top_info,0,sizeof(top_info));
    memset(&graph,0,sizeof(graph));


    linkedQueueCreat(qQ);
    init_t(&graph);
    print_t(&graph);
#if 1
    status= BFS(&graph,qQ);
    if(status != 0)
    {
       printf("BFS failed\n");
    }
#endif

    clearLinkedQueue(qQ);

    return 0;
}
