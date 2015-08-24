#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;
struct Stack
{
    int top;
    unsigned int capacity;
    int* arr;
};
struct Stack* createSTack(unsigned int capacity)
{
    struct Stack* STack=new Stack;
    STack->capacity=capacity;
    STack->top=-1;
    STack->arr=new int[capacity];
    return STack;
};
int isFull(Stack* STack)
{
    if(STack->top==STack->capacity-1)
        return 1;
    return 0;
}
int isEmpty(Stack* STack)
{
    if(STack->top==-1)
        return 1;
    else return 0;
}
void push(Stack* STack,int item)
{
    if(isFull(STack))
        return ;
    STack->arr[++STack->top]=item;
    cout<<item<<" pushed to stack ";
    cout<<endl;
}
int pop(Stack* STack)
{
    if(isEmpty(STack))
        return INT_MIN;
    return STack->arr[STack->top--];
}
int peep(Stack* STack)
{
    if(isEmpty(STack))
        return INT_MIN;
    return STack->arr[STack->top];
}
int main()
{
    struct Stack* STack=createSTack(100);
    push(STack,10);
    push(STack,20);
    push(STack,30);
    push(STack,40);
    push(STack,50);
    cout<<endl;
    cout<<pop(STack);
    cout<<" has been popped from stack ";
    cout<<" NewTop item is "<<peep(STack);
    return 0;
}
