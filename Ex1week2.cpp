#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    
    double dai, rong;

    if (argc != 3)
    {
        printf("Wrong!!\n");
        printf("Syntax : rect <dai> <rong>\n");
        return 1;
    }

    dai = atof(argv[1]);
    rong = atof(argv[2]);
    
    printf("Dien tich la :%f\n",dai * rong);
    printf("Chu vi la: %f\n", 2*(dai +rong));

    return 0;
    
}
