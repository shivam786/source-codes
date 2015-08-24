#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;
struct QNode
{
    int key;
    struct QNode *next;
};
struct Queue
{
    struct QNode *Front, *Rear;
};

struct QNode* newNode(int k)
{
    struct QNode *temp = new QNode;
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *q = new Queue;
    q->Front = q->Rear = NULL;
    return q;
}

void enQueue(struct Queue *q, int k)
{
    struct QNode *temp = newNode(k);
    if (q->Rear == NULL)
    {
       q->Front = q->Rear = temp;
       return;
    }
    q->Rear->next = temp;
    q->Rear = temp;
}
struct QNode *deQueue(struct Queue *q)
{
    if (q->Front == NULL)
       return NULL;
    struct QNode *temp = q->Front;
    q->Front = q->Front->next;

    if (q->Front == NULL)
       q->Rear = NULL;
    return temp;
}

int main()
{
    struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    struct QNode *n = deQueue(q);
    if (n != NULL)
     cout<<" Dequeued item is "<<n->key;
    return 0;
}
