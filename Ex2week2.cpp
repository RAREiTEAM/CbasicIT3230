#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    char s[5];
    int n;

    if (argc != 3)
    {
        printf("Wrong!!\n");
        printf("Syntax : rect <word> <time>\n");
        return 1;
    }
    strcpy(s, argv[1]);
    n = atoi(argv[2]);

    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%s",s);
    }
    

}
