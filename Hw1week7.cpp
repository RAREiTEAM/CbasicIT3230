#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char tel[12];
    char email[40];
} phoneaddr;

struct node {
    phoneaddr addr;
    struct node* next;
};

struct node *root = NULL;
struct node *cur = NULL;
int n = 0;

void insertAtHead(phoneaddr data) {
   struct node *link = (struct node*)malloc(sizeof(struct node));
   strcpy(link->addr.name, data.name);
   strcpy(link->addr.tel, data.tel);
   strcpy(link->addr.email, data.email);
   link->next = root;
   root = link;
   cur = root;
}
void insertAfterCurrent(phoneaddr addr) {
    struct node *new = malloc(sizeof(phoneaddr));
    new->addr = addr;
    if (root == NULL)
    {
        root = new;
        cur = root;
    }
    else if (cur == NULL)
        printf("Current is null!\n");
    else
    {
        new->next = cur->next;
        cur->next = new;
        cur = cur->next;
    }
}
void printList() {
    struct node *ptr = root;
    //start from the beginning
    int i = 0;
    printf("No      Model              Memory       Screen      Price\n");
    while (ptr != NULL)
    {
        printf("%-3d %-30s %-15s %-15s\n",
               ++i,
               ptr->addr.name,
               ptr->addr.tel,
               ptr->addr.email);
        ptr = ptr->next;
    }
    printf("\n");
}

void printNode(struct node *ptr) {
    if (ptr == NULL) {
        printf("This node is null.\n");
    }
    printf("    %-30s %-15s %-15s\n",
        ptr->addr.name,
        ptr->addr.tel,
        ptr->addr.email);
}

void phoneBook(FILE *fin) {
    phoneaddr tmp;
    while (fread(&tmp, sizeof(phoneaddr), 1, fin)) {
        insertAtHead(tmp);
        n++;
    }
    printf("[+] Phonebook\'s address in reversed order:\n");
    printList();
    printf("[+] Current node: \n");
    printNode(cur);
    printf("[-] Do u want to add more contacts? (Y/n): ");
    char ch;
    if ((ch = fgetc(stdin)) == 'n') {
        return;
    }
    printf("[+] How many contacts do u want to add? ");
    int count;  scanf("%d", &count);
    phoneaddr tmp_2[count];
    for (int i = 0; i < count; i++) {
        printf("Person %d: \n", i+1);
        printf("- Name: "); scanf("%s", tmp_2[i].name);
        printf("- Telephone: "); scanf("%s", tmp_2[i].tel);
        printf("- Email: "); scanf("%s", tmp_2[i].email);
    }
    printf("1.    Insert at head\n");
    printf("2.    Insert after current position\n");
    printf("Your selection: ");
    int x;  scanf("%d", &x);
    switch (x) {
        case 1: 
            for (int i = 0; i < count; i++) {
                insertAtHead(tmp_2[i]);
            }
            break;
        case 2: 
            for (int i = 0; i < count; i++) {
                insertAfterCurrent(tmp_2[i]);
            }
            break;
    }
    printList();
    
}

int main(int argc, char* argv[]) {
    FILE *fin;
    if (argc != 2) {
        printf("[!] Wrong syntax!\n");
        printf("[!] Syntax: ./program <destination_file>.\n");
        return 0;
    }
    if ((fin = fopen(argv[1], "r+b")) == NULL) {
        printf("[!] Cannot create %s!\n", argv[2]);
        return 0;
    }
    phoneBook(fin);
    fclose(fin);
    return 0;
}
