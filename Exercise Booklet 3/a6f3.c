#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 10

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main(){
    QueueType Queue1;
    QueueElementType AnItem, i;

    printf("---a---\n");
    CreateQ(&Queue1);

    /*a*/
    for (i=0;i<QueueLimit;i++)
    {
        AddQ(&Queue1, i);
    }
    TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d\n", Queue1.Front, Queue1.Rear, Queue1.Count);

    /*b*/
    printf("---b---\n");
    AddQ(&Queue1, 31);
    TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d\n",Queue1.Front, Queue1.Rear, Queue1.Count);

    /*c*/
    AnItem=Queue1.Front;
    RemoveQ(&Queue1, &AnItem);
    printf("---c---\n");
    TraverseQ(Queue1);
    printf("Removed item=%d Front=%d Rear=%d Count=%d\n", AnItem, Queue1.Front, Queue1.Rear, Queue1.Count);

    /*d*/
    printf("---d---\n");
    AddQ(&Queue1, 25);
    TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d\n", Queue1.Front, Queue1.Rear, Queue1.Count);

    /*e*/
    printf("---e---\n");
    AddQ(&Queue1, 30);
    TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d\n", Queue1.Front, Queue1.Rear, Queue1.Count);

    /*f*/
    printf("---f---\n");
    while (!EmptyQ(Queue1))
    {
         AnItem=Queue1.Front;
         RemoveQ(&Queue1, &AnItem);
         TraverseQ(Queue1);
         printf("Removed item=%d Front=%d Rear=%d Count=%d\n", AnItem, Queue1.Front, Queue1.Rear, Queue1.Count);
    }
    system("pause");
    return 0;
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Count) == (QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue ->Count=(Queue ->Count - 1);
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
        Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Count=(Queue ->Count + 1);
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
    int current, i;
    current = Queue.Front;
	printf("Queue: ");
	if(EmptyQ(Queue))
    printf("Empty Queue");
	for(i=0;i<Queue.Count;i++) {
        printf("%d ", Queue.Element[current]);
        current=(current+1)%QueueLimit;
	}
	printf("\n");
}
