#include<stdio.h>
#include<string.h>
// Distribution counting
 /*int dem(char a[], int m[]){
	int i, j;
	for(i = 0; i < strlen(a); i++){
		if(a[i] != 32)
		m[a[i]]++;
 	}
}
int main(){
	char a[100];
	printf("Nhap chuoi :");fflush(stdin);
	gets(a);
	int m[256]={0};
	dem(a,m);
	int i = 0;
	for(i = 0;i < 256;i++){
		if(m[i] != 0 ){
		printf("ki tu %c xuat hien %d lan \n",(char)(i),m[i]);
		}
	}
}
*/
// cach 2
int kiemtra(char a[],int i){
	int kt=0;
	int j;
     for(j=0; j <= i; j++)
     if(a[i] == a[j]) kt++;  
     if(kt>1)return 0;
     return 1;  
}
int dem(char a[], int m[]){
	int i, j;
	for(i = 0; i < strlen(a); i++){
		for(j=0;j< strlen(a); j++)
		if(a[i]==a[j]&&a[i] != ' ' && kiemtra(a,i) == 1)
		m[i]++;
 	}
}
int main(){
	char a[1000];
	printf("Nhap chuoi :");fflush(stdin);
	gets(a);
	int m[256]={0};
	dem(a,m);
	int i ;
	for(i = 0;i < 256;i++){
		if(m[i] != 0 && kiemtra(a,i) == 1 ){
		printf("ki tu %c xuat hien %d lan \n",a[i],m[i]);
		}
	}
}


