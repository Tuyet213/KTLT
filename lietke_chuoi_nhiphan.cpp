#include<stdio.h>

int l[20];
int n;

void in(){
	for(int i=1;i<=n;i++) printf("%d",l[i]);
	printf("\n");
}

void dayb(int i){
	for(int j=0;j<=1;j++){
		l[i]=j;
		if(i==n) in();
		else dayb(i+1);
	}
}

int main(){
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0||n>10);
	dayb(1);

	return 1;
}
