#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100
#define MAXPOWER 888


using namespace std;
struct GRAPH
{
	int array_apex[MAX];
	int array[MAX][MAX];
	int apex, edge;
};
int init_power_t(struct GRAPH *matt);
int Prime_t(struct GRAPH *mat,int start);
