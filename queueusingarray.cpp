#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;
struct Queue
{
    int Front,Rear,sz;
    unsigned int capacity;
    int *arr;
};
struct Queue* createQueue(unsigned int capacity)
{
    struct Queue* Q = new Queue;
    Q->capacity = capacity;
    Q->Front = Q->sz = 0;
    Q->Rear = capacity - 1;
    Q->arr = new int[capacity];
    return Q;
}

int isFull(struct Queue* Q)
{  return (Q->sz == Q->capacity);  }

int isEmpty(struct Queue* Q)
{  return (Q->sz == 0); }

void enqueue(struct Queue* Q, int item)
{
    if (isFull(Q))
        return;
    Q->Rear = (Q->Rear + 1)%Q->capacity;
    Q->arr[Q->Rear] = item;
    Q->sz = Q->sz + 1;
    cout<<endl;
    cout<<item<<" enqueued to queue "<<endl;
}

int dequeue(struct Queue* Q)
{
    if (isEmpty(Q))
        return INT_MIN;
    int item = Q->arr[Q->Front];
    Q->Front = (Q->Front + 1)%Q->capacity;
    Q->sz = Q->sz - 1;
    return item;
}

int Front(struct Queue* Q)
{
    if (isEmpty(Q))
        return INT_MIN;
    return Q->arr[Q->Front];
}
int Rear(struct Queue* Q)
{
    if (isEmpty(Q))
        return INT_MIN;
    return Q->arr[Q->Rear];
}
int main()
{
    struct Queue* Q=createQueue(1000);
    enqueue(Q,10);
    enqueue(Q,20);
    enqueue(Q,30);
    enqueue(Q,40);
    enqueue(Q,50);
    cout<<endl;
    cout<<dequeue(Q)<<" dequeued from queue "<<endl;
    cout<<endl;
    cout<<" Front Item is "<<Front(Q);
    cout<<endl;
    cout<<" Rear Item is "<<Rear(Q);
    return 0;
}
