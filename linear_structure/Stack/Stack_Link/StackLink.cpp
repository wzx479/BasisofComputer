#include "Stack.h"
using namespace std;

void HandleStack()
{
     int INS=10;
     int OUT=4;
     Stack<int> *t1= new Stack<int>;
     t1->AddStack(INS);
     t1->OutStack(OUT);
     t1->Traverse();
     t1->Size_t();
     delete(t1);
}
