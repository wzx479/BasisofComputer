#include "queue.h"
using namespace std;


int main()
{
    int i;
    cout << "holle new world" <<endl;
    struct linkedQueue *qQ;
    linkedQueueCreat(qQ);

    for(i=0;i<5;i++)
    {
       enLinkedQueue(qQ,i);
    }
    clearLinkedQueue(qQ);
    return 0;
}
