#include<stdio.h>
#include<string.h>
enum{
	SUCCESS, FAIL
};
void charReadWrite(FILE *fin, FILE *fout){
    int c;
    while ((c=fgetc(fin)) != EOF)
    {
        fputc(c,fout);
        if (c == '\n')
        {
            fputc('\n', fout);
        }
        
        
    }
    
}
main(void){
	FILE *fptr1, *fptr2;
	char filename[]="lab1.txt";
    char filename1[]="lab1w.txt";
	int reval = SUCCESS;
	
	if((fptr1 = fopen(filename, "r"))== NULL){
		printf("Cannot open %s.\n", filename);
		reval = FAIL;
	}
	else if ((fptr2 = fopen(filename1, "w"))== NULL)
    {
        printf("Cannot write %s.\n", filename1);
		reval = FAIL;
    }
    else{
        charReadWrite(fptr1,fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
	return reval;
}
