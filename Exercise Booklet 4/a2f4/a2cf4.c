#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;           /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� int */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������

typedef struct ListNode {
    ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);

int main(){
    int i, num;
    ListPointer AList, BList, FinalList, PredPtr=NULL;
    ListElementType Item;

    CreateList(&AList);
    CreateList(&BList);
    CreateList(&FinalList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d", &num);
    for(i=0; i<num; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, PredPtr);
    }

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf("%d", &num);
    for(i=0; i<num; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d", &Item);
        LinkedInsert(&BList, Item, PredPtr);
    }

    printf("LISTA 1:\n");
    LinkedTraverse(AList);
    printf("\n");
    printf("LISTA 2:\n");
    LinkedTraverse(BList);
    printf("\n");

    concat_list(AList, BList, &FinalList);

    printf("SYNENWMEN� LISTA:\n");
    LinkedTraverse(FinalList);
    return 0;
}

void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList)
{
    ListPointer CurrPtr, PredPtr;

    //A
    CurrPtr=AList;
    PredPtr=NULL;
    while(CurrPtr!=NULL)
    {
        LinkedInsert(FinalList,CurrPtr->Data,PredPtr);
        CurrPtr = CurrPtr->Next;
    }

    //B
    CurrPtr=BList;
    PredPtr=NULL;
    while(CurrPtr!=NULL)
    {
        LinkedInsert(FinalList,CurrPtr->Data,PredPtr);
        CurrPtr = CurrPtr->Next;
    }
}

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
    ListPointer TempPtr;

    TempPtr= (ListPointer)malloc(sizeof(struct ListNode));

    TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}
