#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;
struct StackNode
{
    int data;
    struct StackNode* next;
};
int isEmpty(struct StackNode* root)
{
    if(root!=0)
        return 0;
    return 1;
}
void push(struct StackNode** root,int data)
{
    struct StackNode* sn=new StackNode;
    sn->data=data;
    sn->next=*root;
    *root=sn;
    cout<<endl;
    cout<<data<<" pushed onto stack "<<endl;
}
int pop(StackNode** root)
{
    if(isEmpty(*root))
        return INT_MIN;
    StackNode* temp=*root;
    *root=(*root)->next;
    int popped=temp->data;
    delete temp;
    return popped;
}
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
int main()
{
    struct StackNode* root=NULL;
    push(&root,10);
    push(&root,20);
    push(&root,30);
    push(&root,40);
    push(&root,50);
    cout<<endl;
    cout<<pop(&root)<<" popped from stack ";
    cout<<" New Top Element is "<<peek(root);
    cout<<endl;
    return 0;
}
