#include<stdio.h>

int tong(int n){
	if(n==1) return 1;
	return tong(n-1)+n;
}

float tongchia(int n){
	if(n==1) return 1;
	return tongchia(n-1)+1.0/tong(n);
}

int main(){
	int n;
	printf("Nhap gia tri n: ");
	scanf("%d",&n);
	printf("Ket qua la: %f",tongchia(n));
	return 1;
}
