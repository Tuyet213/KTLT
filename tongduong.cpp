#include<stdio.h>

int tongduong(int a[], int l, int r){
	if(l==r){
		if(a[l]%2==0&&a[l]>0) return a[l];
		else return 0;
	}else{
		int m=(l+r)/2;
		return tongduong(a,l,m)+tongduong(a,m+1,r);
	}
}

int main(){
	int a[]={-2,4,6,8,3,-10};
	printf("%d",tongduong(a,0,5));
	return 1;
}
