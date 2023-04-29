#include<stdio.h>
#include<math.h>

int mu2(int n){
	if(n==1) return 1;
	return mu2(n-1)+pow(n,2);
}

int main(){
	int n;
	printf("Nhao gia tri n: ");
	scanf("%d",&n);
	printf("Ket qua la: %d",mu2(n));
	return 1;
}
