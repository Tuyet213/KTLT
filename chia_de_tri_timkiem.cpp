#include<stdio.h>

void nhapmang(int a[],int t[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=5||n>=100);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		t[i]=i; 
	}
		
}

void xuatmang(int a[], int n){
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}

void hoanvi(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void sapxep(int a[],int t[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j]) {
				hoanvi(a[i],a[j]);
				hoanvi(t[i],t[j]);
			}
}

int timx(int a[], int t[], int l, int r, int x){
	if(l==r){
		if(a[l]==x) return t[l];
		else return -1;
	}
	else{
		int m=(l+r)/2;
		if(a[m]==x) return t[m];
		else{
			if(x<a[m]) return timx(a,t,l,m-1,x);
			else return timx(a,t,m+1,r,x);
		} 
	}
}
int main(){
	int a[30];
	int t[30]; 
	int n;
	nhapmang(a,t,n);
	sapxep(a,t,n);
	printf("%d",timx(a,t,0,n-1,5));
	return 1;
}
