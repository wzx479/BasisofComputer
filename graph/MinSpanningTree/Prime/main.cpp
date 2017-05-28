#include "prime.h"

int main()
{
	int rstatus = 0;
	int lowest_power = 0;
	struct GRAPH mat;
	memset(&mat, '\0', sizeof(mat));
	rstatus = init_power_t(&mat);
	lowest_power = Prime_t(&mat,0);
	printf("the lowest_power is %d \n",lowest_power);

	return 0;
}

