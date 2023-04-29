#include<stdio.h>

int soao(int a[], int l, int r){
	if(l==r){
		if(a[l]==l+1) return l+1;
		else return -1;
	}
	int m=(l+r)/2;
	int x=soao(a,l,m);
	int y=soao(a,m+1,r);
	if(x!=-1) return x;
	if(y!=-1) return y; 
}
int soao1(int a[], int l, int r){
	if(l<=r){
		int m=(l+r)/2;
		if(a[m]==m+1) return m+1;
		
//		if(a[m]>m+1) return soao1(a,m+1,r); 
//		if(a[m]<m+1) return soao1(a,l,m-1);
	if(a[m]>m+1) return soao1(a,l,m-1); 
		if(a[m]<m+1) return soao1(a,m+1,r);
	} 
	 return -1;
}
int main(){
	int a[]={1,2,4,5,6,7,7} ;
	int n=7;
	printf("%d\n",soao(a,0,n-1)); 
	printf("%d",soao1(a,0,n-1)); 
} 
