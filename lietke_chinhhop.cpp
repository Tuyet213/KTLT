#include<stdio.h>

int l[20];
int t[20];

void in(int l[], int n){
	printf("(");
	for(int i=1;i<n;i++) printf("%d,",l[i]);
	printf("%d)\n",l[n]);
}

void lk_chinhhop(int i, int m, int n){
	for(int j=1;j<=n;j++){
		if(t[j]==0){
			t[j]=1;
			l[i]=j;
			if(i==m) in(l,m);
			else lk_chinhhop(i+1,m,n);
			t[j]=0; 
		}
	}
}

int main(){
	lk_chinhhop(1,2,3);
	return 1;
}
