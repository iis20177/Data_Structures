#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int AM;
    char FirstName[20];
    char LastName[20];
    char Gender;
    int Year;
    float Grade;
} details;

typedef struct
{
    int am;
    int aa;
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
boolean EmptyBST(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade(float theGrade);
void writeNewStudents(BinTreePointer *Root, int *size);

int main(){
    BinTreeElementType index;
    BinTreePointer ARoot, LocPtr;
    int size;
    details student;
    boolean found;
    float theGrade;

    //1
    printf("Q1. Build BST from a file\n");
    size=BuildBST(&ARoot);

    //2
    printf("Q2. Print size and BST\n");
    printf("Size=%d\n", size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    printf("\n");

    //3
    printf("Q3. Write new students, update file and BST\n");
    writeNewStudents(&ARoot, &size);

    //4
    printf("Q4. Print size and BST\n");
    printf("Size=%d\n", size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    printf("\n");

    //5
    printf("Q5. Search for a student\n");
    printf("Give student's code? ");
    scanf("%d", &index.am);
    RecBSTSearch(ARoot, index, &found, &LocPtr);
    if (found==TRUE)
    {
        PrintStudent(LocPtr->Data.aa);
    }
    else
    {
        printf("The student with this code was not found\n");
    }

    //6
    printf("Q6. Print size and BST\n");
    printf("Size=%d\n", size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    printf("\n");

    //7
    printf("Q7. Print students with grades >= given grade\n");
    printf("Give the grade: ");
    scanf("%f", &theGrade);
    printStudentsWithGrade(theGrade);

    return 0;
}

int BuildBST(BinTreePointer *Root)
{
    FILE *fp;
    int nscan;
    char termch;
    details student;
    BinTreeElementType indexRec;
    int size;

    CreateBST(Root);

    fp=fopen("foitites.dat", "r");
    size=0;
    if (fp!=NULL) {
        while (TRUE){
            nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c", &student.AM, student.FirstName, student.LastName, &student.Gender, &student.Year, &student.Grade, &termch);
            if (nscan==EOF)
                {
                    break;
                }
            if (nscan != -1 && termch != '\n')
                {
                    printf("Error\n");
                    exit(1);
                }
            else{
                indexRec.am=student.AM;
                indexRec.aa=size;
                RecBSTInsert(Root, indexRec);
                size++;
            }
        }
        fclose(fp);
        return size;
    }
}

void writeNewStudents(BinTreePointer *Root, int *size)
{
    int j=*size;
    char ch;
    FILE *fp;
    details student;
    BinTreeElementType indexRec;
    boolean found;
    BinTreePointer LocPtr;

    fp=fopen("foitites.dat", "a");
    if (fp!=NULL) {
        do{
            printf("Give student's AM? ");
            scanf("%d", &indexRec.am);
            RecBSTSearch(*Root, indexRec, &found, &LocPtr);
            if (found==FALSE){
                student.AM = indexRec.am;
                printf("Give student surname? ");
                scanf("%s", &student.LastName);
                printf("Give student name? ");
                scanf("%s", &student.FirstName);
                printf("Give student sex F/M? ");
                scanf(" %c", &student.Gender);
                getchar();
                printf("Give student's registration year? ");
                scanf("%d", &student.Year);
                printf("Give student's grade? ");
                scanf("%f", &student.Grade);
                indexRec.aa = j++;
                RecBSTInsert(Root, indexRec);
                fprintf(fp,"%d,%s,%s,%c,%d,%.1f\n", student.AM, student.FirstName, student.LastName, student.Gender, student.Year, student.Grade);
                *size = *size + 1;
                printf("Size=%d\n", *size);
            }
            else
                {
                    printf("AM already exists in file\n");
                }

            printf("\nContinue Y/N:");
            do{
                scanf("%c", &ch);
            }while (ch != 'n' && ch != 'N' && ch != 'Y' && ch != 'y');
        }while(ch != 'n' && ch != 'N');
        fclose(fp);
    }
}

void PrintStudent(int RecNum){
    FILE *fp;
    int nscan;
    char termch;
    details student;
    BinTreeElementType indexRec;
    int lines;

    fp=fopen("foitites.dat", "r");
    lines=0;
    if (fp!=NULL) {
        while (lines<=RecNum){
            nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c", &student.AM, student.FirstName, student.LastName, &student.Gender, &student.Year, &student.Grade, &termch);
            if (nscan==EOF)
            {
                break;
            }
            if (nscan != EOF && termch != '\n')
            {
                printf("Error\n");
                exit(1);
            }
            lines++;
        }
        if (lines==RecNum+1){
            printf("%d,%s,%s,%c,%d,%.1f\n", student.AM, student.FirstName, student.LastName, student.Gender, student.Year, student.Grade);
        }
    }
    fclose(fp);
}

void printStudentsWithGrade(float theGrade)
{
    FILE *fp;
    int nscan;
    char termch;
    details student;

    fp=fopen("foitites.dat", "r");
    if (fp!=NULL) {
            while (TRUE){
                nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c", &student.AM, student.FirstName, student.LastName, &student.Gender, &student.Year, &student.Grade, &termch);
                if (nscan==EOF)
                {
                    break;
                }
                if (nscan != EOF && termch != '\n')
                {
                    printf("Error\n");
                    exit(1);
                }
                else
                    {
                        if (student.Grade >= theGrade)
                        {
                            printf("%d,%s,%s,%c,%d,%.1f\n", student.AM,student.FirstName,student.LastName,student.Gender,student.Year,student.Grade);
                        }
                    }
            }
            fclose(fp);
    }
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.am < LocPtr ->Data.am)
            LocPtr = LocPtr ->LChild;
        else if (Item.am > LocPtr ->Data.am)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.am);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data.am = Item.am;
        LocPtr ->Data.aa = Item.aa;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.am < Parent ->Data.am)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    boolean stop;

    *LocPtr = Root;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.am < (*LocPtr)->Data.am)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (KeyValue.am > (*LocPtr)->Data.am)
                *LocPtr = (*LocPtr)->RChild;
            else stop = TRUE;
    }
   *Found=stop;
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("(%d, %d), ", Root->Data.am,Root->Data.aa);
        RecBSTInorder(Root->RChild);
    }
}
