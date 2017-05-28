
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    int marked;
    struct edge *top_next;
} SadjList,AdjList[MAX];   /*两条链结构，数组可以更好的区分*/

struct attribute
{
    AdjList top_info;
     int apex;
     int edge;
};

void init_t( struct attribute *graph);
void  print_t(struct attribute *graph);
int BFS(struct attribute *graph,struct linkedQueue *qQ);
