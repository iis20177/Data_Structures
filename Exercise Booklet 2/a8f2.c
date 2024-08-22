#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 15

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
boolean EmptyStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean FullStack(StackType Stack);

int main(){
    StackType S;
    StackElementType item, ch, enter;
    boolean valid, flag;

    flag = FALSE;
    valid = TRUE;
    CreateStack(&S);

    printf("Enter string:\n");
    scanf("%c", &ch);
    getchar();

    if (ch == '#')
    {
        return(0);
    }
    while ((ch != '#') && (valid == TRUE))
    {
        if (flag == FALSE)
        {
            if (ch == 'C')
            {
                flag = TRUE;
                scanf("%c", &ch);
                getchar();
            }
            else
            {
                Push(&S, ch);
                scanf("%c", &ch);
                getchar();
            }
        }
        else
        {
            if (!EmptyStack(S))
            {
                Pop(&S, &item);
                if (item != ch)
                {
                    valid = FALSE;
                }
                else
                {
                    scanf("%c", &ch);
                    getchar();
                }
            }
            else
            {
                valid = FALSE;
            }
        }
    }
    if ((valid == TRUE) && (EmptyStack(S)))
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}
