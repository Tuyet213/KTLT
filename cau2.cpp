#include<stdio.h>
#define Mul(x,y) x*y

int main(){
	int a;
	int b;
	printf("Nhap a va b: ");
	scanf("%d%d",&a,&b);
	printf("Tich cua %d va %d la %d", a+1,b+2,Mul(a+1,b+2));
	return 1;
}
