#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void push(node** head_ref,int new_data)
{
    struct node* new_node=new node;
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void printrever(struct node* head)
{
    if(head==NULL)
        return;
    printrever(head->next);
    cout<<head->data<<" ";
}
int main()
{
    struct node* head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    printrever(head);
    return 0;
}
