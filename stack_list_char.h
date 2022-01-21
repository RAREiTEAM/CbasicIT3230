#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char elementtype2;

typedef struct StackType_t_char{
    elementtype2 *element;
    struct StackType_t_char *next;
} StackType_char;
 
void push_op(elementtype2 *element, StackType_char **top);
elementtype2 *pop_op(StackType_char **top);
elementtype2 *peek_op(StackType_char **top);

char *copyString(char *str)
{
    char *tmp = malloc(strlen(str) + 1);
    if (tmp)
        strcpy(tmp, str);
    return tmp;
}

void push_op(elementtype2 *element, StackType_char **top)
{
    StackType_char* temp;
    temp =(StackType_char*)malloc(sizeof(StackType_char));
    if (!temp)
    {
        printf("\nHeap Overflow");
        exit(1);
    }
    temp->element = copyString(element);
    temp->next = *top;
    *top = temp;
}
 
int isEmpty_op(StackType_char *top)
{
    return (top == NULL);
}
 
elementtype2 *peek_op(StackType_char **top)
{
    if (!isEmpty_op(*top))
        return (*top)->element;
    else
    {
        printf("Empty stack!");
        exit(1);
    }
    
}
 
elementtype2 *pop_op(StackType_char **top)
{   
    elementtype2 *tmp;
    StackType_char* p;
    if (isEmpty_op(*top))
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    else
    {
        tmp = (*top)->element;
        p = *top;
        *top = (*top)->next;
        free(p);
        return tmp;
    }
}
