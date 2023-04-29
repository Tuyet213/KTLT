#include<stdio.h>
#include<math.h>

void nhap(int a[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0||n>=100);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
}

int demboi3(int a[], int n){
	if(n==0) return 0;
	if(a[n-1]%3==0) return demboi3(a,n-1)+1;
	else return demboi3(a,n-1);
}
int chinhphuong(int n){
	int k=sqrt(n);
	if(k*k==n) return 1;
	else return 0;
}

int tongcp(int a[], int n){
	if(n==0) return 0;
	if(chinhphuong(a[n-1])) return tongcp(a,n-1)+a[n-1];
	else return tongcp(a,n-1);
}

int main(){
	int a[30];
	int n;
	nhap(a,n);
//	printf("%d",demboi3(a,n));
printf("%d",tongcp(a,n));
	return 1;
}
