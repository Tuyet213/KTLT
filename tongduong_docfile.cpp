#include<stdio.h>

int a[30];
int n;

void docfile(){
	FILE *f=fopen("mangnguyen.txt","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++) fscanf(f,"%d",&a[i]);
		fclose(f);
		}
}

int tongduong(int a[], int l, int r){
	if(l==r){
		if(a[l]%2==0&&a[l]>0) return a[l];
		else return 0;
	}
	else{
		int m=(l+r)/2;
		return tongduong(a,l,m)+tongduong(a,m+1,r);
	}
}

int main(){
	docfile();
	printf("%d",tongduong(a,0,n-1));
	return 1;
}
