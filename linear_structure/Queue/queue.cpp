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

//��ӣ���ʽ���в������������
void enLinkedQueue(struct linkedQueue *qQ,int val)
{
	struct linkedQueueNode * pNew = (struct linkedQueueNode *)malloc(sizeof(struct linkedQueueNode));
	if( NULL == pNew )
	{
		printf("enLinkedQueue(): malloc failed!\n");
		exit(-1);
	}

	pNew->data = val;
	qQ->pRear->pNext = pNew;//�Ӷ�β�룬��pNewָ��Ľ��ҵ�����β��
	pNew->pNext = NULL;
	qQ->pRear = pNew;//βָ������

	return;

}

int linkedQueueEmpty(struct linkedQueue *qQ)
{
	if( qQ->pFront == qQ->pRear)
	    return 1;
	else
	    return 0;
}

//���ӣ�Ҫ�ж��Ƿ�Ϊ��
void outLinkedQueue(struct linkedQueue *qQ,int *pVal)
{
	if( linkedQueueEmpty(qQ) )
	{
		printf("linkedQueue is Empty!\n");
		return;
	}

	struct linkedQueueNode * pTemp = qQ->pFront->pNext;//�Ӷ�ͷ���ӣ�pHeadָ��Ľ�㲻���ӣ�������û��ʵ�����塣���׽����pHead->pNextָ��Ľ�㡣
	printf("data is %d\n",pTemp->data);
	*pVal = pTemp->data;
	qQ->pFront->pNext = pTemp->pNext;
	free(pTemp);

	if( NULL == qQ->pFront->pNext )
	{
		qQ->pFront = qQ->pRear;//���������һ��Ԫ�ر�ɾ���󣬶���βָ��Ҳ��ʧ�ˣ������Զ�βָ�����¸�ֵ����ָ��ͷ��㡣
	}

	return;
}

//�������У������ض��еĳ���
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

//��ն��У�ʹ���Ϊ�ն��У���ܻ���
int clearLinkedQueue(struct linkedQueue *qQ)
{
	int pVal=0;

	while( !(linkedQueueEmpty(qQ)) )
           outLinkedQueue(qQ,&pVal);

	return 0;
}
