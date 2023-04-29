#include<stdio.h>
int a[]={0,2,2,2,5,4,4,5,9,11,11};
int n=11;
int vitri(int a[], int l, int r){
	if(l==r){
		if(a[l]==l+1) return l+1;
		else return -1;
	}
	else{
		int m=(l+r)/2;
		if(a[m]>m) return vitri(a,l,m);
		else return vitri(a,m+1,r);
	}
//	if(l<=r){
//		int m=(l+r)/2;
//		if(a[m]==m+1) return m+1;
//		if(a[m]>m+1) return vitri(a,m,r);
//		if(a[m]<m+1) return vitri(a,l,m); 
//	} 
//	return -1;
}

int main(){
	printf("%d",vitri(a,0,n-1));
	return 1;
}
