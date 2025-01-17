#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxElements 50

typedef float HeapElementType;
typedef struct {
    HeapElementType key;
} HeapNode;

typedef struct {
     int Size;
     HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
void PrintHeap(HeapType Heap);

int main(){
    int nscan;
    char termch;
    HeapType AHeap;
    HeapNode AnItem;
    int m;
    FILE *fp;

    printf("Give m: " );
    scanf("%d", &m);
    CreateMinHeap(&AHeap);
    fp=fopen("transactions.txt", "r");
    if(fp!=NULL){
        while(TRUE){
            nscan=fscanf(fp,"%f%c", &AnItem.key, &termch);
            if (nscan==EOF)
                {
                    break;
                }
            if (nscan != -1 && termch != '\n')
                {
                    printf("Error\n");
                    exit(1);
                }
            else
                {
                    InsertMinHeap(&AHeap, AnItem);
                }
            if (AHeap.Size>m)
                {
                    DeleteMinHeap(&AHeap, &AnItem);
                }
        }
        fclose(fp);
    }
    PrintHeap(AHeap);

    printf("Transactions\n");
    while (!EmptyHeap(AHeap)){
        DeleteMinHeap(&AHeap, &AnItem);
        printf("%.2f ", AnItem.key);
    }
return 0;
}

void PrintHeap(HeapType Heap)
{
    int i;
    printf("Data structure size=%d\n", Heap.Size);
    for (i=1;i<=Heap.Size;i++)
    printf("%.2f ", Heap.Element[i].key);
    printf("\n");
}

void CreateMinHeap(HeapType *Heap)
{
    (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
{
    return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
{
    return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
{
    int hole;
    if (!FullHeap(*Heap))
    {
        (*Heap).Size++;
        hole=(*Heap).Size;
        while (hole>1 && Item.key < Heap->Element[hole/2].key){
                (*Heap).Element[hole]=(*Heap).Element[hole/2];
                hole=hole/2;
            }
        (*Heap).Element[hole]=Item;
    }
    else printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
{
    int parent, child;
    HeapNode last;
    boolean done;
    if (!EmptyHeap(*Heap))
        {
            done=FALSE;
            *Item=(*Heap).Element[1];
            last=(*Heap).Element[(*Heap).Size];
            (*Heap).Size--;
            parent=1;
            child=2;
            while (child<=(*Heap).Size && !done)
                {
                    if (child<(*Heap).Size)
                        if ((*Heap).Element[child].key > (*Heap).Element[child+1].key)
                                child++;
                    if (last.key <= (*Heap).Element[child].key)
                            done=TRUE;
                    else
                    {
                        (*Heap).Element[parent]=(*Heap).Element[child];
                        parent=child;
                        child=2*child;
                    }
                }
            (*Heap).Element[parent]=last;
        }
    else printf("Empty heap...\n");
}
