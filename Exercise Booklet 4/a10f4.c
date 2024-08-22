#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define StackLimit 100

typedef char StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
void TraverseStack(StackType Stack);

int main()
{
    int plithos, i;
    StackType AStack1,AStack2;
    StackElementType item;

    CreateStack(&AStack1);

    printf("PLITHOS STOIXEIWN: ");
    scanf("%d", &plithos);
    for (i=0;i<plithos;i++)
    {
        printf("DWSE TO %do STOIXEIO: ",i+1);
        scanf("%d", &item);
        Push(&AStack1,item);
    }

    printf("*********1i stoiva***********\n");
    TraverseStack(AStack1);

    CreateStack(&AStack2);

    while(!EmptyStack(AStack1))
    {
        Pop(&AStack1,&item);
        Push(&AStack2,item);
    }

    printf("*********2i stoiva***********\n");
    TraverseStack(AStack2);
    return 0;
}

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;

}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    for (i=Stack.Top;i>=0;i--)
    printf("%d ",Stack.Element[i]);
    printf("\n");
}
