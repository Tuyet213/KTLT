#include<stdio.h>

int demx(int a[], int n, int x){
	if(n-1==0) return 0;
	if(a[n-1]==x) return demx(a,n-1,x)+1;
	return demx(a,n-1,x); 
} 

int main(){
	int a[100]={1,5,9,4,6,2,4,0,4};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Ket qua la %d.",demx(a,n,4)); 
} 
