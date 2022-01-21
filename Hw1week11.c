#include"stack_list_int.h"
#include"stack_list_char.h"

StackType_int *s1 = NULL;
StackType_char *s2 = NULL;
void menu();
void add2Stack();
void viewTop();
void removeFromStack();

void add2Stack(){
    elementtype1 e;
    printf("Push :");
    scanf("%d", &e);
    push(e, &s1);

    elementtype2 task[20];
    sprintf(task, "push %d", e);
    push_op(task, &s2);
    printf("\nInteger %d has been pushed to stack\n", e);

}
void removeFromStack(){
    elementtype1 tmp = peek(&s1);
    pop(&s1);
    printf("Integer %d has been removed from stack\n", tmp);
    char task[10];
    sprintf(task,"pop %d", tmp);
    push_op(task, &s2);
}

void viewTop(){
    printf("Integer on top of the stack: %d",peek(&s1));
}

void undo(){
    char *task = peek_op(&s2);
    printf("Previous task: %s\n", task);
    char *data = strtok(task, " ");
    data = strtok(NULL," ");
    elementtype1 value = atoi(data);

    if(task[1] == 'u'){
        pop(&s1);
        pop_op(&s2);
    }
    else{
        push(value, &s1);
        pop_op(&s2);
    }
}

void menu(){
    printf("\n-----Menu-----\n");
    printf("1. Add 1 integer in stack.\n");
    printf("2. View top.\n");
    printf("3. Remove from stack contains integer 1 element.\n");
    printf("4. Undo.\n");
    printf("Choose:");
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        add2Stack();
        menu();
        break;
    case 2:
        viewTop();
        menu();
        break;
    case 3:
        removeFromStack();
        menu();
        break;
    case 4:
        undo();
        menu();
        break;
    default:
        break;
    }

}



int main(){
    menu();
}
