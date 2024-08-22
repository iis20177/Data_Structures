#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους

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

void insert_list_m_elements(ListPointer *List, int n);

int main(){
    ListPointer AList, PredPtr=NULL;
    ListElementType item;
    int i, n, num;

    CreateList(&AList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &num);
    for(i=0;i<num;i++)
    {
        printf ("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d", &item);
        LinkedInsert(&AList, item, PredPtr);
    }

    printf("*********Arxiki lista************\n");
    LinkedTraverse(AList);
    printf("\n");

    printf("DWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA: ");
    scanf("%d", &n);
    insert_list_m_elements(&AList, n);
    printf("*********Teliki lista************\n");
    LinkedTraverse(AList);
    return 0;
}

void insert_list_m_elements(ListPointer *List, int n)
{
    ListPointer TempPtr;
    int i,j,m;
    ListElementType item;

    if(EmptyList(*List))
    {
        printf("EMPTY LIST\n");
    }
    else
    {
        TempPtr=*List;
        i=1;
        while(TempPtr->Next!=NULL && i<n){
            TempPtr=TempPtr->Next;
            i++;
        }
        if(sizeof(TempPtr)<n || n<1){
            printf("ERROR\n");
        }
        else
        {
            printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN:");
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA: ");
                scanf("%d",&item);
                LinkedInsert(List,item,TempPtr);
                TempPtr=TempPtr->Next;
            }
        }
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
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
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
