#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define QueueLimit 4

typedef struct {
    int arrival, stay, start, end;
} QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                         τύπος struct (δομή) */
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void ReadCustomer(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void TraverseQ(char NameQ[15], QueueType Queue);

int main(){
    QueueType WaitingQueue, ServiceQueue;
    int i;
    char NameQ[15];

    CreateQ(&WaitingQueue);
    for (i=1; i<QueueLimit; i++)
    {
        printf("Give: arrival time,stay time for client %d: ", i);
        ReadCustomer(&WaitingQueue);
    }

    TraverseQ(NameQ, WaitingQueue);

    ServiceQueue = TimesInQueue(&WaitingQueue);

    strcpy(NameQ,"WaitingQueue");
    TraverseQ(NameQ, WaitingQueue);
    strcpy(NameQ,"ServiceQueue");
    TraverseQ(NameQ, ServiceQueue);
    return 0;
}

void ReadCustomer(QueueType *Queue){
    QueueElementType tmpCustomer;
    scanf("%d,%d", &tmpCustomer.arrival, &tmpCustomer.stay);
    tmpCustomer.start = -1;
    tmpCustomer.end = -1;
    AddQ(Queue, tmpCustomer);
}

QueueType TimesInQueue(QueueType *Queue){
    int earliestStart=0;
    int currentStart=0;
    int currentEnd=0;

    QueueType QueueServiced;
    QueueElementType CurrentCust;

    CreateQ(&QueueServiced);

    while (!EmptyQ(*Queue))
    {
        RemoveQ(Queue, &CurrentCust);

        if (CurrentCust.arrival>earliestStart)
        {
            currentStart = CurrentCust.arrival;
        }
        else
        {
            currentStart = earliestStart;
        }

        currentEnd = currentStart + CurrentCust.stay;

        earliestStart = currentEnd;

        CurrentCust.start = currentStart;
        CurrentCust.end = currentEnd;

        AddQ(&QueueServiced, CurrentCust);
    }
    return QueueServiced;
}

void TraverseQ(char NameQ[15], QueueType Queue){
    int current;
    int i=1;
    int j;

    if (!EmptyQ(Queue))
    {
        for(j=0;NameQ[j]!='\0';j++)
        {
            printf("%c", NameQ[j]);
        }
        printf("\n");
        current = Queue.Front;
        printf("Client \t\tStart\tEnd\tArrival\tStay\n");

        while (current!=Queue.Rear)
        {
            printf("Client %d %d %d %d %d\n", i, Queue.Element[current].start,Queue.Element[current].end,Queue.Element[current].arrival,Queue.Element[current].stay);
            i++;
            current = (current+1)%QueueLimit;
        }
    }
    else
    {
        for(j=0;NameQ[j]!='\0';j++)
        {
            printf("%c", NameQ[j]);
        }
        printf(" is empty\n");
    }
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit; ;
	}
	else
		printf("Full Queue");
}
