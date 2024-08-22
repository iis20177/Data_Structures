#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int Prot;
    int Code;
} QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

void insert_prot(QueueType *Queue, QueueElementType Item);

int main()
{
    int i, plithos;
    QueueType AQueue;
    QueueElementType AnItem;

    CreateQ(&AQueue);

    printf("DWSE TO PLITHOS: ");
    scanf("%d", &plithos);
    for(i=0;i<plithos;i++)
    {
        printf("DWSE TON KODIKO TOU %dou KOMVOU:", i+1);
        scanf("%d", &AnItem.Code);
        printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ", i+1);
        scanf("%d", &AnItem.Prot);
        insert_prot(&AQueue, AnItem);
    }

    printf("----------Priority Queue-------------\n");
    TraverseQ(AQueue);
    return 0;
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
    QueuePointer TempPtr, CurrPtr, PredPtr;
    boolean flag;
    TempPtr=(QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data=Item;
    TempPtr->Next=NULL;
    if (EmptyQ(*Queue))
    {
        Queue->Front=TempPtr;
        Queue->Rear=TempPtr;
    }
    else{
        PredPtr=Queue->Front;
        CurrPtr=Queue->Front;
        flag=FALSE;
        if(CurrPtr->Data.Prot>TempPtr->Data.Prot)
        {
            Queue->Front=TempPtr;
            TempPtr->Next=CurrPtr;
        }
        else
        {
            while (CurrPtr!=NULL && flag==FALSE)
            {
                if (CurrPtr->Data.Prot>TempPtr->Data.Prot)
                {
                    PredPtr->Next=TempPtr;
                    TempPtr->Next=CurrPtr;
                    flag=TRUE;
                }
                PredPtr=CurrPtr;
                CurrPtr=CurrPtr->Next;
            }
            if (flag==FALSE)
            {
                PredPtr->Next=TempPtr;
                Queue->Rear=TempPtr;
            }
        }
    }
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.Prot, CurrPtr->Data.Code);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
