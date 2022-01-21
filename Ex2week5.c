#include<stdio.h>
//dung de quy in 50 so tu nhien lien tiep
int number(int n){
    if(n<=50){
        printf("%d ", n);
        number(n+1);
    }
}

int main(){
    number(1);
}
