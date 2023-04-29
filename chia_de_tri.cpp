#include<stdio.h>

int S1(int a, int l, int r){
	if(l==r){
		return a;
	}
	else{
		int m=(l+r)/2;
		return S1(a,l,m)*S1(a,m+1,r);
	}
}

int S2(int l, int r){
	if(l==r) return l*l;
	int m=(l+r)/2;
	return S2(l,m)+S2(m+1,r);
}

int S3(int a[], int l, int r){
	if(l==r) return a[l];
	int m=(l+r)/2;
	return S3(a,l,m) + S3(a,m+1,r);
}

int main(){
	printf("2^5=%d",S1(2,1,5));
	return 1;
}
