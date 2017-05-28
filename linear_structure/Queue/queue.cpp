#include "queue.h"
using namespace std;

void linkedQueueCreat(struct linkedQueue *qQ)
{
	qQ->pFront = (struct linkedQueueNode *)malloc(sizeof(struct linkedQueueNode));
	if( NULL == qQ->pFront )
	{
		printf("linkedQueueCreat(): malloc failed!\n");
		exit(-1);
	}
	qQ->pRear = qQ->pFront;
	qQ->pRear->pNext = NULL;
	return;
}

//入队，链式队列不存在满的情况
void enLinkedQueue(struct linkedQueue *qQ,int val)
{
	struct linkedQueueNode * pNew = (struct linkedQueueNode *)malloc(sizeof(struct linkedQueueNode));
	if( NULL == pNew )
	{
		printf("enLinkedQueue(): malloc failed!\n");
		exit(-1);
	}

	pNew->data = val;
	qQ->pRear->pNext = pNew;//从队尾入，把pNew指向的结点挂到队列尾部
	pNew->pNext = NULL;
	qQ->pRear = pNew;//尾指针上移

	return;

}

int linkedQueueEmpty(struct linkedQueue *qQ)
{
	if( qQ->pFront == qQ->pRear)
	    return 1;
	else
	    return 0;
}

//出队，要判断是否为空
void outLinkedQueue(struct linkedQueue *qQ,int *pVal)
{
	if( linkedQueueEmpty(qQ) )
	{
		printf("linkedQueue is Empty!\n");
		return;
	}

	struct linkedQueueNode * pTemp = qQ->pFront->pNext;//从队头出队，pHead指向的结点不出队，这个结点没有实际意义。队首结点是pHead->pNext指向的结点。
	printf("data is %d\n",pTemp->data);
	*pVal = pTemp->data;
	qQ->pFront->pNext = pTemp->pNext;
	free(pTemp);

	if( NULL == qQ->pFront->pNext )
	{
		qQ->pFront = qQ->pRear;//当队列最后一个元素被删除后，队列尾指针也丢失了，因此需对队尾指针重新赋值，即指向头结点。
	}

	return;
}

//遍历队列，并返回队列的长度
void traverseLinkedQueue(struct linkedQueue *qQ,int *linkedQueueLen)
{
	int i=0;
	struct linkedQueueNode * pTemp = qQ->pFront->pNext;

	while( pTemp != NULL )
	{
		i++;
		printf("data-%d is %d\n",i,pTemp->data);
		pTemp = pTemp->pNext;
	}

	*linkedQueueLen = i;

	return;
}

//清空队列，使其变为空队列，框架还在
int clearLinkedQueue(struct linkedQueue *qQ)
{
	int pVal=0;

	while( !(linkedQueueEmpty(qQ)) )
           outLinkedQueue(qQ,&pVal);

	return 0;
}
