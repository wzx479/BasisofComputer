#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct linkedQueueNode
{
	int data;
	struct linkedQueueNode *pNext;
};

struct linkedQueue
{
	struct linkedQueueNode * pFront;
	struct linkedQueueNode * pRear;
};

void linkedQueueCreat(struct linkedQueue *qQ);
void enLinkedQueue(struct linkedQueue *qQ,int val);
int linkedQueueEmpty(struct linkedQueue *qQ);
void outLinkedQueue(struct linkedQueue *qQ,int *pVal);
void traverseLinkedQueue(struct linkedQueue *qQ,int *linkedQueueLen);
int clearLinkedQueue(struct linkedQueue *qQ);

