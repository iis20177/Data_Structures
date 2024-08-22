#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define megisto_plithos 1000

typedef enum{
    FALSE, TRUE
}boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void displayset(typos_synolou set);
void createFibonacciSet (stoixeio_synolou threshold, typos_synolou synolo);
boolean isFibonacci(stoixeio_synolou candidate, typos_synolou synoloFibonacci);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);


main()
{
    typos_synolou synoloFibonacci;
    stoixeio_synolou max,tmp;
    max=0;
    while ((max<2) || (max>1000))
    {
        printf("Dwse ton megisto arithmo: ");
        scanf("%d", &max);
    }

    createFibonacciSet(max, synoloFibonacci);
    displayset(synoloFibonacci);
    tmp = 0;
    while(tmp>=0)
    {
        printf("Enter number to check : ");
        scanf("%d", &tmp);
        if (tmp>=0 && tmp<=1000)
        {
            if (isFibonacci(tmp, synoloFibonacci))
            {
               printf("Fibonacci!\n");
            }
            else
            {
                printf("Not Fibonacci...\n");
            }
        }
    }
    system("PAUSE");
}

void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i=0; i<megisto_plithos; i++)
        synolo[i] = FALSE;
}

void createFibonacciSet (stoixeio_synolou threshold, typos_synolou synolo)
{
    stoixeio_synolou f1, f2, tmp;
    stoixeio_synolou i;
    Dimiourgia(synolo);
    f1 = 0;
    f2 = 1;
    Eisagogi(f1, synolo);
    while (f2<=threshold)
    {
        Eisagogi(f2,synolo);
        tmp = f1+f2;
        f1 = f2;
        f2 = tmp;

    }
}

boolean isFibonacci(stoixeio_synolou candidate, typos_synolou synoloFibonacci)
{
    if(Melos(candidate,synoloFibonacci))
        return TRUE;
    else
        return FALSE;
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0; i<megisto_plithos; i++)
	{
		if(set[i]==TRUE)
			printf(" %d",i);
	}
	printf("\n");
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}
