#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 100

typedef struct {
     int price;
     char size;
}StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void TraverseStack(StackType Stack);

int main()
{
    StackElementType fanela[StackLimit], AnItem, top;
    StackType itemsStack, tempStack;
    boolean found;
    char size;
    int i, n;

    CreateStack(&itemsStack);
    CreateStack(&tempStack);

    printf("Give number of items ");
    scanf("%d", &n);

    printf("\nGive the items to store\n");
    for (i=0; i<n; i++)
    {
        printf("Give price ");
        scanf("%d", &fanela[i].price);
        printf("Give size ");
        scanf(" %c", &fanela[i].size);
        Push(&itemsStack, fanela[i]);
    }

    printf("\nItems in the box");
    TraverseStack(itemsStack);

    printf("What size do you want? ");
    scanf(" %c", &size);
    found = FALSE;
    while ((!EmptyStack(itemsStack)) && (found == FALSE))
    {
        Pop(&itemsStack, &AnItem);
        if (AnItem.size == size)
        {
            found = TRUE;
        }
        else
        {
            Push(&tempStack, AnItem);
        }
    }
    if (found == TRUE)
    {
        printf("Found the size");
    }
    else
    {
        printf("Not Found the size");
    }
    printf(" %c\n\n", size);

    printf("Items in the box");
    TraverseStack(itemsStack);
    printf("Items out of the box");
    TraverseStack(tempStack);

    while (!EmptyStack(tempStack))
    {
        Pop(&tempStack, &top);
        Push(&itemsStack, top);
    }

    printf("Items in the box");
    TraverseStack(itemsStack);
    printf("Items out of the box");
    TraverseStack(tempStack);
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
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, %d\n", Stack.Element[i].size, Stack.Element[i].price);
    }
    printf("\n");
}
