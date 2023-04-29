#include<stdio.h>

int l[20];

void in(int l[], int n){
	printf("(");
	for(int i=1;i<n;i++) printf("%d,",l[i]);
	printf("%d)\n",l[n]);	
}

void lk_tohop(int i, int m, int n){
	for(int j=l[i-1]+1;j<=n-m+i;j++){
		l[i]=j;
		if(i==m) in(l,m);
		else lk_tohop(i+1,m,n);
	}
}

int main(){
//	l[0]=0;
	lk_tohop(1,2,3);
	return 1;
}
