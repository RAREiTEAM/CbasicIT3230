#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define B 100
typedef int KeyType;
typedef struct Node
{
    KeyType Key;
    struct Node *Next;
} Node;
typedef Node *Position;
typedef Position Dictionary[B];
Dictionary D;

int H(KeyType x)
{
    return (x % 100);
}

void MakeNullISet()
{
    int i;
    for (i = 0; i < B; i++)
        D[i] = NULL;
}

int Search(KeyType X)
{
    Position P;
    int Found = 0;
    P = D[H(X)];
    while ((P != NULL) && (!Found))
        if (P->Key == X)
            Found = 1;
        else
            P = P->Next;
    return Found;
}

void InsertSet(KeyType X)
{
    int Bucket;
    Position P;
    if (!Search(X))
    {
        Bucket = H(X);
        P = D[Bucket];
        D[Bucket] = (Node *)malloc(sizeof(Node));
        D[Bucket]->Key = X;
        D[Bucket]->Next = P;
    }
}

void DeleteSet(KeyType X)
{
    int Bucket, Done;
    Position P, Q;
    Bucket = H(X);
    // If list has already existed
    if (D[Bucket] != NULL)
    {
        // if X at the head of the list
        if (D[Bucket]->Key == X)
        {
            Q = D[Bucket];
            D[Bucket] = D[Bucket]->Next;
            free(Q);
        }
        else
        { // Search for X
            Done = 03;
            P = D[Bucket];
            while ((P->Next != NULL) &&
                   (!Done))
                if (P->Next->Key == X)
                    Done = 1;
                else
                    P = P->Next;
            if (Done)
            { // If found
                // Delete P->Next
                Q = P->Next;
                P->Next = Q->Next;
                free(Q);
            }
        }
    }
}

int emptybucket(int b)
{
    return (D[b] == NULL ? 1 : 0);
}

int empty()
{
    int b;
    for (b = 0; b < B; b++)
        if (D[b] != NULL)
            return 0;
    return 1;
}

void clearbucket(int b)
{
    Position p, q;
    q = NULL;
    p = D[b];
    while (p != NULL)
    {
        q = p;
        p = p->Next;
        free(q);
    }
    D[b] = NULL;
}

void clear()
{
    int b;
    for (b = 0; b < B; b++)
        clearbucket(b);
}

void traversebucket(int b)
{
    Position p;
    p = D[b];
    while (p != NULL)
    {
        // Assume that the key is of int type
        printf("%d\t", p->Key);
        p = p->Next;
    }
}

void traverse()
{
    int b;
    for (b = 0; b < B; b++)
    {
        printf("\nBucket %d:", b);
        traversebucket(b);
    }
}

int A[1000];
void khoitao()
{
    time_t t;
    srand((unsigned)time(&t));
    int i = 0;
    while (i < 1000)
    {
        A[i] = (rand() % 1000);
        i++;
    }

    printf("Creat done!\n");
}

void Insert()
{
    for (int i = 0; i < 1000; i++)
    {
        InsertSet(A[i]);
    }
}

void menu()
{
    printf("\nMenu\n");
    printf("1.Khoi tao [0:1000]\n");
    printf("2.Chen\n");
    printf("3.Search\n");
    printf("4.Add\n");
    printf("5.Print\n");
    printf("6.Delete\n");
    printf("Choose :");
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        khoitao();
        menu();
        break;
    case 2:
        Insert();
        menu();
        break;
    case 4:
        printf("Nhap so muon them:");
        int add;
        scanf("%d", &add);
        if (Search(add))
        {
            printf("Da xuat hien.\n");
        }
        else
        {
            InsertSet(add);
            printf("Da chen xong !\n");
        }

        menu();
        break;
    case 5:
        traverse();
        menu();
        break;
    case 6:
        printf("Nhap phan tu muon xoa :");
        int del;
        scanf("%d", &del);
        DeleteSet(del);
        menu();
        break;

    default:
        break;
    }
}

int main()
{
    menu();
}
