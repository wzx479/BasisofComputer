#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99
using namespace std;
struct edge
{
    int adjvex;
    struct edge *next;
};

typedef struct top
{
    int data;
    struct edge *top_next;
}AdjList[MAX];   /*两条链结构，数组可以更好的区分*/

struct attribute
{
    AdjList top_info;
     int apex;
     int edge;
};

void init_t( struct attribute *graph)
{
    struct edge *edgecode;
    int i=0,j=0,k=0;
    cout << "Please input the apex and edge" << endl;
    cin >> graph->apex >> graph->edge;

    for(i=0;i<graph->apex;i++)
    {
        cout<<"plz input the apex graph"<< endl;
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

        edgecode = (struct edge *)malloc(sizeof(edgecode));/*内部malloc的指针，可以传递给传进来的指针；可是都是传进来的指针就得指针的指针*/
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
int main()
{
    AdjList top_info;
    struct attribute graph;
    memset(&top_info,0,sizeof(top_info));
    memset(&graph,0,sizeof(graph));
    init_t(&graph);
    print_t(&graph);
    return 0;
}
