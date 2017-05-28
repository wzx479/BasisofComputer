#include "prime.h"

int init_power_t(struct GRAPH *matt)
{
	int i, j, k;
	int power = 0;
	printf("plz input the num of apex and edge \n");
	cin >> matt->apex >> matt->edge;

	for (i=0;i<matt->apex;i++)
	{
		for (j=0;j<matt->edge;j++)
		{
				matt->array[i][j] = MAXPOWER;
		}
	}
	for (k=0;k<matt->edge;k++)
	{
		printf("plz input each edge's apex\n");
		cin >> i >> j;
		printf("plz input each edge's power\n");
		cin >> power;
		if( i>=matt->apex || i>=matt->apex || k>=matt->edge )
		{
			break;
		}
		matt->array[i][j] = power;
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

int Prime_t(struct GRAPH *matt,int start)
{
    int vetex_new[MAX];
    int lowpower[MAX];
    int min = MAXPOWER;
    int i,j,k;
    int sum =0;
    int vetex_id = 0;
    int n = matt->apex;
    memset(vetex_new,0,sizeof(vetex_new));
    memset(lowpower ,0,sizeof(lowpower));

    for( i=0; i< n; i++)
    {
        vetex_new[i] = -9;
        lowpower[i] = matt->array[start][i];
    }

    vetex_new[start] = 0;


    for( k=0;k <n-1;k++ )
    {
        min = MAXPOWER;
        for( i=0;i<n;i++)
        {
            if( -9 == vetex_new[i] && lowpower[i] < min )
            {
                min = lowpower[i];
                vetex_id = i;
            }
        }
        printf("vetex_id = %d , min = %d \n",vetex_id,min);

        if ( min < MAXPOWER )
        {
            sum += min;
            vetex_new[vetex_id] = 0;

            for( j=0;j<n;j++ )
            {
                if( -9 == vetex_new[j] && matt->array[vetex_id][j] < lowpower[j]  )
                {
                    lowpower[j] = matt->array[vetex_id][j];
                }
                printf(" lowpower[%d] =  %d \t",j,lowpower[j]);
            }
            printf("\n");
        }
    }
    return sum;
}
