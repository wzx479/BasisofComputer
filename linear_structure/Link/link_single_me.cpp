#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
#define MAX 10

typedef struct node_t
{
    int DATA;
    struct node_t *next;
}nodes;
/*head is node too,not define again*/
/*
struct HEAD
{
    int head;
};
*/
nodes  *create()
{
    nodes *head;
    head=(nodes*)malloc(sizeof(nodes));
    head->next = NULL;
    head->DATA = 0;
    return head;
}

int add_t(nodes *head)
{
    int i=0;
    nodes *nodeinfo;
    head->DATA= i;
    for (i=1;i<MAX;i++)
    {
         nodeinfo = (nodes*)malloc(sizeof(nodes));
         nodeinfo->DATA=i;
         nodeinfo->next = head->next ;
         head->next = nodeinfo;
    }
    return 0;
}

int print_t(nodes *head)
{
    int i=0;
    for(i=0;i<MAX;i++)
    {
        cout << head->DATA <<endl;
        head = head->next;
    }
    return 0;
}

int dele_code (nodes *head)
{
    nodes *off_node;
    off_node = head-next;
    off_node = NULL:
    head=head->next;
    return 0;
}

int dele_t (nodes *head)
{
    int i=0;
    int rstatus=0;
    for (i=1;i<3;i++)
    {
         rstatus = dele_code(head);
    }
    return rstatus;
}

void release(nodes *head)
{
    head->next=NULL;
    delete head;
}

int main()
{
    int rstatus=0;
    cout << "Hello queue!" << endl;
    nodes *head;

    head=create();

    rstatus= add_t(head);

    rstatus= dele_t(head);

    rstatus= print_t(head);

    release(head);
    return rstatus;
}
