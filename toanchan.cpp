#include<stdio.h>

int toanchan(int n){
	if(n<10){
		if(n%2==0) return 1;
		else return 0;
	}
	else{
		if(n%2==0) return toanchan(n/10);
		else return 0;
	}
}

void intoanchan(int n){
	for(int i=1;i<=n;i++) if(toanchan(i)) printf("%d ",i);
}

int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<10||n>10000);
	intoanchan(n);
	return 1;
}
