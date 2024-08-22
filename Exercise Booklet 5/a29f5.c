#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int AMKA;
    int AFM;
    int Age;
} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
void RecBSTInOrder(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);

int main(){
    char ch;
    int i;
    BinTreePointer Root1, Root2, LocPtr;
    BinTreeElementType person;
    boolean found;

    CreateBST(&Root1);
    CreateBST(&Root2);

    do
    {
        printf("Give AMKA? ");
        scanf("%d", &person.AMKA);
        printf("Give AFM? ");
        scanf("%d", &person.AFM);
        printf("Give age? ");
        scanf("%d", &person.Age);

        if (person.Age<=60)
        {
            BSTInsert(&Root1, person);
        }
        else
        {
            BSTInsert(&Root2, person);
        }

        printf("\n");
        printf("Continue Y/N:");
        do
        {
            scanf("%c", &ch);
        }
        while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    }
    while (toupper(ch)!= 'N');

    printf("People with age less-equal 60\n");
    RecBSTInOrder(Root1);
    printf("\n\n");
    printf("People with age greater than 60\n");
    RecBSTInOrder(Root2);
    printf("\n");

    for (i=0; i<3; i++)
    {
        printf("Give AMKA: ");
        scanf("%d", &person.AMKA);
        printf("Give age: ");
        scanf("%d", &person.Age);
        if (person.Age<=60)
        {
            BSTSearch(Root1, person, &found, &LocPtr);
        }
        else
        {
            BSTSearch(Root2, person, &found, &LocPtr);
        }
        if (found==TRUE)
        {
            if(person.Age==LocPtr->Data.Age)
            {
                printf("The person with AMKA %d, AFM 20 and age %d is in the catalogue\n", person.AMKA, person.Age);
            }
            else
            {
                printf("The person with AMKA %d has age %d different from the person you are looking for\n", person.AMKA, person.Age);
            }
        }
        else
        {
            printf("The person with AMKA %d and age %d is Unknown\n", person.AMKA, person.Age);
        }
    }

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

void RecBSTInOrder(BinTreePointer Root)
{
    if (Root!=NULL) {
        RecBSTInOrder(Root->LChild);
        printf("(%d, %d, %d)", Root->Data.AMKA, Root->Data.AFM, Root->Data.Age);
        RecBSTInOrder(Root->RChild);
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
        if (Item.AMKA < LocPtr ->Data.AMKA)
            LocPtr = LocPtr ->LChild;
        else if (Item.AMKA > LocPtr ->Data.AMKA)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.AMKA);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        //LocPtr ->Data = Item;
        LocPtr ->Data.AMKA = Item.AMKA;
        LocPtr ->Data.AFM=Item.AFM;
        LocPtr ->Data.Age=Item.Age;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.AMKA < Parent ->Data.AMKA)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
{

    boolean stop;

    *LocPtr = Root;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.AMKA < (*LocPtr)->Data.AMKA)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (KeyValue.AMKA > (*LocPtr)->Data.AMKA)
                *LocPtr = (*LocPtr)->RChild;
            else stop = TRUE;
    }
   *Found=stop;
}
