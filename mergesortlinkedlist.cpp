#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

struct node* SortedMerge(node* a, node* b);
void FrontBackSplit(node* source, node** frontRef, node** backRef);

void MergeSort(struct node** headRef)
{
    node* head = *headRef;
    node* a;
    node* b;
    if ((head == NULL) || (head->next == NULL))
        return;
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}
node* SortedMerge(struct node* a, struct node* b)
{
    node* result = NULL;
    if (a == NULL)
        return b;
    else if (b==NULL)
        return a;
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}
void FrontBackSplit(node* source, node** frontRef, node** backRef)
{
    node* fast;
    node* slow;
    if (source==NULL || source->next==NULL)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

void printList(node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<endl;
        node = node->next;
    }
}
void push(node** head_ref, int new_data)
{
    node *new_node = new node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    node* res = NULL;
    node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    printList(a);
    cout<<endl;
    MergeSort(&a);
    cout<<"\n Sorted Linked List is: \n";
  //  printList(a);
    return 0;
}
