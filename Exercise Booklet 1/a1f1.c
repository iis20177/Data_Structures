#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 201

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);

void createPrimeSet(typos_synolou s, stoixeio_synolou first, stoixeio_synolou last);
void displaySet(typos_synolou set, stoixeio_synolou first, stoixeio_synolou last);
boolean isPrime(stoixeio_synolou n);

int main()
{
    stoixeio_synolou Synolo, f, l;
    typos_synolou set;
    do
        {
            printf("Give first number:");
            scanf("%d", &f);
        }
    while (f<2 || f>200);

    do
        {
            printf("Give last number:");
            scanf("%d", &l);
        }
    while ((l<2 || l>200) || (f>=l));

    createPrimeSet(set, f, l);
    displaySet(set, f, l);
}

void createPrimeSet(typos_synolou s, stoixeio_synolou first, stoixeio_synolou last)
{
    stoixeio_synolou i;
    for (i=0; i<megisto_plithos; i++)
    {
        s[i] = FALSE;
    }
    for (i=2; i<megisto_plithos; i++)
    {
        if (isPrime(i))
        {
            Eisagogi(i, s);
        }
    }
}

void displaySet(typos_synolou set, stoixeio_synolou first, stoixeio_synolou last)
{
	stoixeio_synolou i;
	for (i=0; i<megisto_plithos; i++)
	{
		if(Melos(i,set))
			printf(" %d", i);
	}
	printf("\n");
}

boolean isPrime(stoixeio_synolou n)
{
    stoixeio_synolou i, limit;

    if (n==2)
    {
        return TRUE;
    }
    if (n%2==0)
    {
        return FALSE;
    }
    limit = n/2;
    for (i=3; i<limit; ++i)
    {
        if (n%i==0)
        {
            return FALSE;
        }
    }

    return TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}
