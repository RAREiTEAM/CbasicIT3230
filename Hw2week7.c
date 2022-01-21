#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char model_name[40];
    char memory[20];
    float screen;
    char price[10];
} product;

struct node {
    product phone;
    struct node* next;
};

int n = 0, phone_status = 0;
void menu();
struct node *root = NULL, *cur = NULL;

void printNode(struct node *ptr) {
    printf("[+] Current position:\n");
    printf(
        "%-30s %-20s %-10.2f %-3s\n",
        ptr->phone.model_name,
        ptr->phone.memory,
        ptr->phone.screen,
        ptr->phone.price);
}

void insertAtHead(product phone) {
   struct node *link = (struct node*)malloc(sizeof(struct node));
   strcpy(link->phone.model_name, phone.model_name);
   strcpy(link->phone.memory, phone.memory);
   strcpy(link->phone.price, phone.price);
   link->phone.screen = phone.screen;
   link->next = root;
   root = link;
   cur = root;
}

void insertAfterCurrent(product phone) {
    struct node *new = malloc(sizeof(product));
    new->phone = phone;
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
    printf("No   Model                          Memory               Screen     Price ($)\n");
    while (ptr != NULL)
    {
        printf(
            "%-4d %-30s %-20s %-10.2f %-3s\n",
            i++,
            ptr->phone.model_name,
            ptr->phone.memory,
            ptr->phone.screen,
            ptr->phone.price
        );
        ptr = ptr->next;
    }
    printf("\n");
    menu();
}

void importFromText() {
    FILE *fin;
    if ((fin = fopen("PhoneDB.txt", "r")) == NULL) {
        printf("Cannot open file \'PhoneDB.txt\'\n");
        return;
    }
    n = 0;
    product tmp;
    while (fscanf(fin, "%s %s %f %s", tmp.model_name, tmp.memory, &tmp.screen, tmp.price) != EOF) {
        n++;
        insertAtHead(tmp);
    }
    fclose(fin);
    printf("[+] Database has been imported successfully!\n");
    phone_status = 1;
    menu();
}

void importFromDat() {
    FILE *fin;
    if ((fin = fopen("PhoneDB.dat", "rb")) == NULL) {
        printf("Cannot open file \'PhoneDB.dat\'\n");
        return;
    }
    n = 0;
    product tmp;
    while (fread(&tmp, sizeof(product), 1, fin)) {
        n++;
        insertAfterCurrent(tmp);
    }
    printList();
    fclose(fin);
    phone_status = 1;
    menu();
}

void searchByModel() {
    char tmp_name[40];
    printf("Phone model name: ");
    scanf("%s", tmp_name);
    struct node *ptr = root;
    int i = 0, found = 0;
    printf("No   Model                          Memory               Screen     Price ($)\n");
    while (ptr != NULL) {
        if (strcmp(ptr->phone.model_name, tmp_name) == 0) {
            found = 1;
            printf(
                "%-4d %-30s %-20s %-10.2f %-3s\n",
                i++,
                ptr->phone.model_name,
                ptr->phone.memory,
                ptr->phone.screen,
                ptr->phone.price
            );
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf("[!] Phone model is not found\n");
    }
    menu();
}

void searchByPrice() {
    float tmp_price;
    printf("Price ($): ");
    scanf("%f", &tmp_price);
    struct node *ptr = root;
    int i = 0, found = 0;
    printf("No   Model                          Memory               Screen     Price ($)\n");
    while (ptr != NULL) {
        if (atof(ptr->phone.price) < tmp_price) {
            found = 1;
            printf(
                "%-4d %-30s %-20s %-10.2f %-3s\n",
                i++,
                ptr->phone.model_name,
                ptr->phone.memory,
                ptr->phone.screen,
                ptr->phone.price
            );
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf("[!] Phone model is not found\n");
    }
    menu();
}

void exportToDat() {
    FILE *fout;
    if ((fout = fopen("PhoneDB.dat", "wb")) == NULL) {
        printf("[!] Cannot open \"PhoneDB.dat\" for writing\n");
        return;
    }
    struct node *ptr = root;
    //start from the beginning
    int i = 0;
    while (ptr != NULL)
    {
        fwrite(&ptr->phone, sizeof(product), 1, fout);
        ptr = ptr->next;
    }
    fclose(fout);
    printf("[+] Data has been written!");
    menu();
}

void manualInsert() {
    product tmp;
    printf("Input new model's information\n");
    printf("    - Model name (eg: Vsmart_Live_4): ");
    scanf("%s", tmp.model_name);
    printf("    - Memory (GB): ");
    scanf("%s", tmp.memory);
    printf("    - Screen (inch): ");
    scanf("%f", &tmp.screen);
    printf("    - Price ($): ");
    scanf("%s", tmp.price);
    printNode(cur);
    printf("[+] Insert this new model:\n");
    printf("1. Before current position\n");
    printf("2. After current position\n");
    printf("3. Back to menu\n");
    printf("Your selection: ");
    int x;
    scanf("%d", &x);
    switch (x) {
        case 1:
            insertAtHead(tmp);
            break;
        case 2:
            insertAfterCurrent(tmp);
            break;
        default:
            menu();
    }
    menu();
}

void menu(){
    printf("\nMenu:\n");
    printf("1. Import from text file \"PhoneDB.txt\"\n");
    printf("2. Import from dat file \"PhoneDB.dat\"\n");
    printf("3. Display list\n");
    printf("4. Search phone by model\n");
    printf("5. Search phone whose price is under the value inputted\n");
    printf("6. Export to dat file \"PhoneDB.dat\"\n");
    printf("7. Manual insertion\n");
    printf("8. Exit\n");
    if (!phone_status)
        printf("[!] Database has not been imported!\n");
    else 
        printf("[!] %d phones have been imported!\n", n);
    printf("Your selection: ");
    int x; scanf("%d", &x);
    switch (x) {
        case 1:
            importFromText();
            break;
        case 2:
            importFromDat();
            break;
        case 3:
            printList();
            break;
        case 4:
            searchByModel();
            break;
        case 5:
            searchByPrice();
            break;
        case 6:
            exportToDat();
            break;
        case 7:
            manualInsert();
            break;
        default:
            return;
    }
}

int main()
{
    menu();
    return 0;
}
