#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct student_struct
{
    int no;
    char phone[12];
    char mssv[10];
    char name[50];
    float score;
} student;

int getNumOfLine(FILE *f);
void textToDat(FILE *fin, FILE *fout, int sl, student *st);
void displayDat(FILE *f, int sl);
void search_update(FILE *f, int sl, student *st);

int main()
{
    int choice;
    FILE *f1, *f2;
    if ((f1 = fopen("bangdiem.txt", "r")) == NULL)
    {
        printf("\nCan not open bangdiem.txt");
        return 1;
    }
    if ((f2 = fopen("grade.dat", "w+b")) == NULL)
    {
        printf("\nCan not open grade.dat");
        return 1;
    }
    int sl = getNumOfLine(f1);
    student *st = (student *)malloc(sl * sizeof(student));
    if (st == NULL)
    {
        printf("\nAllocation failed! Check memory");
        return 1;
    }

    for (;;)
    {
        printf("\n1. TextToDat\n2. Display Dat file\n3. Search and Update.\n4 Quit.");
        printf("\nEnter(1~4):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            textToDat(f1, f2, sl, st);
            break;
        case 2:
            displayDat(f2, sl);
            break;
        case 3:
            search_update(f2, sl, st);
            break;
        default:
            free(st);
            return 0;
        }
    }
    // fclose(f1);
    // fclose(f2);
    free(st);
    return 0;
}

int getNumOfLine(FILE *f)
{
    int count = 0;
    char buff[MAX_LEN];
    while ((fgets(buff, MAX_LEN, f)) != NULL)
    {
        count++;
    }
    return count;
}

void textToDat(FILE *fin, FILE *fout, int sl, student *st)
{
    rewind(fin);
    int i;
    for ( i = 0; i < sl; ++i)
    {
        fscanf(fin, "%d %s %s %s %f",&st[i].no, st[i].mssv, st[i].name, st[i].phone, &st[i].score);
        printf("%-3d%-15s%-20s%-20s\n", st[i].no, st[i].mssv, st[i].name, st[i].phone, st[i].score);
        fwrite(&st[i], sizeof(student), 1, fout);
    }
}

void displayDat(FILE *f, int sl)
{
    rewind(f);
    student *sv = (student *)malloc(sl * sizeof(student));
    if (sv == NULL)
    {
        printf("\nAllocation failed! Check memory");
    }
    int i;
    for ( i = 0; i < sl; ++i)
    {
        fread(&sv[i], sizeof(student), 1, f);
        printf("%-3d%-15s%-20s%-20s\n", sv[i].no, sv[i].mssv, sv[i].name, sv[i].phone, sv[i].score);
    }
    free(sv);
}

void search_update(FILE *f, int sl, student *st)
{
    rewind(f);
    printf("\nEnter MSSV:");
    char mssv_search[10];
    scanf("%s", mssv_search);
    printf("\nEnter score:");
    float score_update;
    scanf("%f", &score_update);
    int i;
    int check = 1;
    for ( i = 0; i < sl; ++i)
    {
        fread(&st[i], sizeof(student), 1, f);
        if (strcmp(st[i].mssv, mssv_search) == 0)
        {
            st[i].score = score_update;
            fseek(f, (-1) * sizeof(student), SEEK_CUR);
            fwrite(&st[i], sizeof(student), 1, f);
            check = 0;
            break;
        }
    }
    if(check) printf("Khong tim thay!!");
}
