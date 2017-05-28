#include "adjacent.h"
#include "queue.h"


void init_t( struct attribute *graph)
{
    struct edge *edgecode;
    int i=0,j=0,k=0;
    cout << "Please input the apex and edge" << endl;
    cin >> graph->apex >> graph->edge;

    for(i=0;i<graph->apex;i++)
    {
        cout<<"plz input the apex graph,plz use 0 as first"<< endl;
        cin >> graph->top_info[i].data;
        graph->top_info[i].top_next = NULL;
    }
#if 1
    for(k=0;k<graph->edge;k++)
    {
        cout << "Please input the edge's two apex graph" << endl;
        cin >> i >> j;

        edgecode = (struct edge *)malloc(sizeof(edgecode));
        edgecode->adjvex = j;
        edgecode->next = graph->top_info[i].top_next;
        graph->top_info[i].top_next =  edgecode;

        edgecode = (struct edge *)malloc(sizeof(edgecode));/*内部malloc的指针，可以传递给函数内部的指针；可是都是传进来的指针就得指针的指针*/
        edgecode->adjvex = i;
        edgecode->next = graph->top_info[j].top_next;
        graph->top_info[j].top_next =  edgecode;
    }
#endif
    return;
}

void  print_t(struct attribute *graph)
{
    int i;
    struct edge *printcode;
    printf("into print_t \n");
    for(i=0;i<graph->apex;i++)
    {
        printcode = graph->top_info[i].top_next;
        printf("%d\t",graph->top_info[i].data);
        while( printcode !=NULL )
        {
            printf("%d\t",printcode->adjvex);
            printcode = printcode->next;
        }
        printf("\n");
    }


    return;
}
/*breadth firstly search,need a queue to transfer data*/
int BFS(struct attribute *graph,struct linkedQueue *qQ)
{

    int i=0,k=0;
    int step=1;
    int len;
    struct edge *s_code;

    s_code =(struct edge *)malloc(sizeof(struct edge ));

    printf("BFS():  %d\n",graph->top_info[i].data);
    sleep (3);

    for( k=0 ; k< graph->apex ;k++)
    {
       graph->top_info[k].marked = 0 ;
    }

    enLinkedQueue(qQ,graph->top_info[i].data );
    graph->top_info[i].marked = 1;

    do
    {
        if(!linkedQueueEmpty(qQ))
        {
            i=qQ->pFront->pNext->data;
            traverseLinkedQueue(qQ,&len);
            sleep (5);
        }
        outLinkedQueue(qQ,&step);
        s_code = graph->top_info[i].top_next;
        while ( s_code !=NULL && graph->top_info[s_code->adjvex ].marked != 1)
        {
             enLinkedQueue( qQ,s_code->adjvex);
             graph->top_info[s_code->adjvex].marked = 1;
             s_code = s_code->next;
        }

        traverseLinkedQueue(qQ,&len);

    }while(!linkedQueueEmpty(qQ));

    return 0;
}
