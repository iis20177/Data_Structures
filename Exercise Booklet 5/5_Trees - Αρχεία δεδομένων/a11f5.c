#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char BinTreeElementType[20];

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
void CreateDictionary(BinTreePointer *Root, FILE *fp);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
int SpellingCheck(BinTreePointer Root, FILE *fp);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);

int main(){
    int count;
    BinTreePointer ARoot;
    FILE* fp1;
    FILE* fp2;

    fp1=fopen("i112f5.txt", "r");

    fp2=fopen("i111f5.txt", "r");

    CreateBST(&ARoot);
    CreateDictionary(&ARoot, fp1);
    printf("**********Dictionary**********\n");
    InorderTraversal(ARoot);
    printf("**********Not in Dictionary**********\n");
    printf("Number of words not in Dictionary: %d\n", count=SpellingCheck(ARoot, fp2));

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

void CreateDictionary(BinTreePointer *Root, FILE* fp)
{
    BinTreeElementType Item;

    while (!feof(fp))
    {
        fscanf(fp, "%s", Item);
        BSTInsert(Root, Item);
    }
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item, LocPtr->Data)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item, LocPtr ->Data)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));

        strcpy(LocPtr ->Data, Item);
        //LocPtr ->Data = Item;

        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item, Parent ->Data)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

int SpellingCheck(BinTreePointer Root, FILE* fp)
{
    boolean Found = FALSE;
    BinTreePointer LocPtr;
    BinTreeElementType Item;
    int count;

    count = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s", Item);
        BSTSearch(Root, Item, &Found, &LocPtr);
        if (Found==FALSE)
        {
            printf("%s\n", Item);
            count++;
        }
    }
    return count;

}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue, (*LocPtr)->Data) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue, (*LocPtr)->Data) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n", Root->Data);
        InorderTraversal(Root->RChild);
    }
}
