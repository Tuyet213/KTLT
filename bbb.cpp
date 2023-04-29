#include<stdio.h>

//void nhap(float a[], int &n){
//	do{
//		printf("Nhap so hoc sinh: ");
//		scanf("%d",&n);
//	}while(n<=0||n>=100);
//	printf("Nhap chieu cao cac hoc sinh: \n");
//	for(int i=0;i<n;i++) scanf("%f",&a[i]);
//}

int dem(float a[], int l, int r){
	if(l==r){
		if((a[l]>=1.5) && (a[l]<=1.7000001)) {
			int dem=a[l];
			return 1;
		}
		else return 0;
	}
	int m=(l+r)/2;
	return dem(a,l,m)+dem(a,m+1,r);
}
int main(){
	float a[]={1.1,1.66,1.67,1.6,1.3,1.5,1.7};
	int n=7;
//	nhap(a,n);
	printf("%d",dem(a,0,n-1));
}
