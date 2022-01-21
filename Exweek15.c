#include <stdio.h>

#define MAX_CHAR 10
#define TABLE_SIZE 13

typedef struct
{
    char key[MAX_CHAR];
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        h[i].key[0] = NULL;
    }
}
int tranform(char *key)
{
    int number = 0;
    while (*key)
    {
        number += *key++;
    }

    return number;
}

int hash(char *key)
{
    return (tranform(key) % TABLE_SIZE);
}

int main()
{
}
