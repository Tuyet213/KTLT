#include<stdio.h>

int n;
int tt[30];
int a[30];
int dem=0;

void nhapmang(int a[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0);
	for(int i=0;i<n;i++){
		do{
		printf("Nap phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
	}while(a[i]<0);
	}
}

void inkq(){
	int S=0;
	int kt=0;
	for(int i=0;i<n;i++){
	if(tt[i]==1) S+=a[i]; else kt++;}
	if(S%2==0&&kt==2){
		dem++;
		for(int i=0;i<n;i++) if(tt[i]==1) printf("%d ",i+1);
		printf("\n");
	}
}

void thu(int i){
	for(int j=0;j<=1;j++){
		tt[i]=j;
		if(i<n-1) thu(i+1);
		else inkq();
		tt[i]=0;
	}
}

int main(){
	nhapmang(a,n);
	thu(0);
	if(dem==0) printf("Khong co cach nao");
	return 1;
}


