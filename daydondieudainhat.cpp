#include<stdio.h>
int a[]={2,3,4,5,8,7};
int n=sizeof(a)/sizeof(a[0]);
int l[30];
int t[30];

void khoitao(){
	for(int i=0;i<n;i++){
		l[i]=1;
		t[i]=-1;
	}
}

void dynamic(){
	for(int i=0;i<n;i++){
		int lmax=0;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]&&lmax<l[j]){
				lmax=l[j];
				t[i]=j;
			}
		}
		l[i]=lmax+1;
	}
}

void in(){
	int max=0;
	int indexmax;
	for(int i=0;i<n;i++) if(l[i]>max){
		max=l[i];
		indexmax=i;
	}
	printf("Day con don dieu dai nhat %d phan tu\n",max);
	printf("Cac phan tu cua day nay la: ");
	int pt[30];
	int k=0;
	while(indexmax>=0){
		pt[k++]=a[indexmax];
//		printf("%d ",a[indexmax]);
		indexmax=t[indexmax];
	}
	k--;
	for(int i=k;i>=0;i--){
		printf("%d ",pt[i]);
	}
}

int main(){
	khoitao();
	dynamic();
	in();
	return 1;
}
