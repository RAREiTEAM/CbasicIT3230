#include<stdio.h>

unsigned int nhan(unsigned int x,unsigned int y){
    if(y == 1){
        return x;
    }
    else if(y > 1){
    return nhan(x, y-1) + x;
    }
    return 0;
}

int main(){
    printf("%d", nhan(3,5));
}
