#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 10

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);

boolean isValidInteger(char str[]);
boolean isValidIdentifier(char str[]);

int main(){
    int i;
    char str[10], answer1='y', answer2='Y';
    while ((answer1 == 'y') || (answer1 == 'Y'))
    {
        printf("Give string: ");
        gets(str);
        for (i=0; str[i] != '\0'; i++)
        {
            if (isValidInteger(str))
            {
                printf("Valid integer\n");
            }
            else
            {
                printf("Not a valid integer\n");
            }
        }
        printf("Continue? Yes or No?\n");
        scanf("%c", &answer1);
    }
    while ((answer2 == 'y') || (answer2 == 'Y'))
    {
        printf("Give string: ");
        gets(str);
        for (i=0; str[i] != '\0'; i++)
        {
            if (isValidIdentifier(str))
            {
                printf("Valid identifier\n");
            }
            else
            {
                printf("Not a valid identifier\n");
            }
        }
        printf("Continue? Yes or No?\n");
        scanf("%c", &answer2);
    }
    return 0;
}

boolean isValidInteger(char str[])
{
    int i;
    stoixeio_synolou plus, minus, index;
    typos_synolou CharacterSet, DigitSet;
    Dimiourgia(CharacterSet);
    plus = 43;
    minus = 45;
    Eisagogi(plus, CharacterSet);
    Eisagogi(minus, CharacterSet);
    Dimiourgia(DigitSet);
    for (index=48; index<57; index++)
    {
        Eisagogi(index, DigitSet);
    }
    for (i=0; str[i] != '\0'; i++)
    {
        if (Melos(str[i], CharacterSet) || Melos(str[i], DigitSet))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

boolean isValidIdentifier(char str[])
{
    int i;
    typos_synolou LetterSet;
    stoixeio_synolou index;
    Dimiourgia(LetterSet);
    for (index=65; index<=90; index++)
    {
        Eisagogi(index, LetterSet);
    }
    for (index=97; index<=122; index++)
    {
        Eisagogi(index, LetterSet);
    }
    for (i=0; str[i] != '\0'; i++)
    {
        if (Melos(str[i], LetterSet))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

boolean KenoSynolo(typos_synolou synolo)
{
    stoixeio_synolou i;
    boolean keno;

    keno=TRUE;
    i = 0;

    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = FALSE;
        else
            i++;
    }
    return keno;
}

boolean IsaSynola(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}
