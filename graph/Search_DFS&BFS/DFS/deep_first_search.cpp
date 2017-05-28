// Graph_Deep.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#define MAX 100

struct GRAPH
{
	int array_apex[MAX];
	int array[MAX][MAX];
	int apex, edge;
};
int init_t(struct GRAPH *matt);
int DFS(struct GRAPH *matt);
int handle(int begin, struct GRAPH *matt, int *view);
int main()
{
	int rstatus = 0;
	struct GRAPH mat;
	memset(&mat, '\0', sizeof(mat));
	rstatus=init_t(&mat);

	rstatus = DFS(&mat);

	return 0;
}

int init_t(struct GRAPH *matt)
{
	int i, j, k;
	printf("plz input the num of apex and edge ,using the format ***,***\n");
	scanf("%d,%d",&matt->apex,&matt->edge);

	for (i=0;i<matt->apex;i++)
	{
		for (j=0;j<matt->edge;j++)
		{
			if (i == j)
			{
				matt->array[i][j] = 0;
			}

		}
	}
	for (k=0;k<matt->edge;k++)
	{
		printf("plz input each edge's apex\n");
		scanf("%d,%d", &i, &j);
		if( i==100 || i>=matt->apex || i>=matt->apex || k>=matt->edge )
		{
			break;
		}
		matt->array[i][j] = 1;
		matt->array[j][i] = matt->array[i][j];
	}
	for (i = 0; i<matt->apex; i++)
	{
		for (j = 0; j<matt->apex; j++)
		{
			printf("%d\t", matt->array[i][j]);
		}
		printf("\n");
	}
    return 0;
}

int DFS(struct GRAPH *matt)
{
	int view[MAX] = { '\0' };
	int i = 0;
	int k;
	int rstatus = 0;
	rstatus=handle(i,matt,view);

	for (k=0;k<matt->apex;k++)
	{
		printf("rsult: the view of %d is %d \n",k,view[k]);
	}

	return 0;
}

int handle(int begin , struct GRAPH *matt ,int *view)
{
	int next;
	if(begin < matt->apex)
	{
		view[begin] = 1;
		for (next = 0; next < matt->apex; next++)
		{
			printf("View[%d]=%d,next=%d,matt->array[begin][next]=%d\n", begin, view[begin], next, matt->array[begin][next]);
			if (matt->array[begin][next] == 1 && view[next] == 0)
			{		
				printf("step in 1\n");
				handle(next, matt, view);
			}

		}
	}
	return 0;
}

