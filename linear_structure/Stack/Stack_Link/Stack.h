#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
template <class T>
struct StackNode
{
    T data;
    StackNode<T> *next;/*struct node *next*/
    StackNode<T> (const& x): data(x)
    {}
};

template <class T>
class Stack
{
public:
    Stack():head(NULL),size(0)
    {
        _init_t(&head);
    }
    ~Stack()
    {
        _Destroy(head);
    }
    void AddStack(T ins_num)
    {
        T i;
        for(i=0;i<ins_num;i++)
        {
            _AddStack(head,i);
        }
        cout<<endl;
    }

    void OutStack(T out_num)
    {
        T i;
        for(i=0;i<out_num;i++)
        {
            _OutStack(head,i);
        }
        cout<<endl;
    }

    void Traverse()
    {
        _Traverse(head);
    }

    void Size_t()
    {
        size = _Size_t(head);
        cout<< "size="<< size <<endl;
    }
private:
    void _init_t(StackNode<T> **head)
    {
        (*head)= new StackNode<T> (0);
        (*head)->next =NULL;
    }
    void _AddStack(StackNode<T> *head,T i)
    {
        StackNode<T> *node = new StackNode<T>(i);
        node->next = head->next;
        head->next = node;
    }

    void _OutStack(StackNode<T> *head,T i)
    {
        if( head->next == NULL )
        {
            return;
        }
        StackNode<T> *node = new StackNode<T>(i);
        node = head->next;
        head->next = node->next;
        node =NULL;
        _Destroy(node);
    }

    void _Destroy(StackNode<T> *node)
    {
        if(node == NULL)
            return;
        _Destroy(node->next);
        delete (node);
    }
    _Traverse(StackNode<T> *head)
    {
        T len=0;
        StackNode<T> *node = new StackNode<T>(0);
        node = head->next;
        while(node != NULL)
        {
            cout<<node->data<<" ";
            node = node ->next;
            len++;
        }
        cout<<endl;
    }
    T _Size_t(StackNode<T> *head)
    {
        T len=0;
        StackNode<T> *node = new StackNode<T>(0);
        node = head->next;
        while(node != NULL)
        {
            cout<<node->data<<" ";
            node = node ->next;
            len++;
        }
        cout<<endl;
        return len;
    }
private:
    StackNode<T> *head;
    T size;
};


void HandleStack();
