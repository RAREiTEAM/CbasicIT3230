#include<stdio.h>

int sosanh(int A[],int B[],int n){
	int i;
	for(i = 0; i < n; i++){
		if(A[i] != B[i]) return 0;
	}
	return 1;
}
int main(){
	int i;
	int n;
	int A[n], B[n];
	printf("mang dai : ");
	scanf("%d",&n);
	printf("\nNhap mang A \n");
	for(i = 0;i < n ;i++){
		printf("A[%d] = ",i);
		scanf(" %d",&A[i]);
	}
	printf("\nNhap mang B \n");
	for(i = 0;i < n;i++){
		printf("B[%d] = ",i);
		scanf(" %d",&B[i]);
	}
	if(sosanh(A,B,n) == 1) 
	printf("hai mang bang nhau");
	else
	printf("hai mang khac nhau");
	getch();
	return 0;
}
