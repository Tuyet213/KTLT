#include<stdio.h>
int v[]={0,3,6,8,2,5};
int w[]={0,4,5,2,1,6};
int n=sizeof(v)/sizeof(v[0]);
int l[30][30];
int m=20;

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

void dynamic(){
	for(int i=1;i<=n;i++)
	for (int j = 1; j <= m; j++)		
	   	if (w[i] <= j )
			l[i][j] = max(l[i-1][j],l[i-1][j-w[i]]+v[i]);	
		else
		    l[i][j] = l[i-1][j];   	
}

void in(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%d ",l[i][j]);
		printf("\n");
	}
}

int main(){
	dynamic();
	in();
	return 1; 
}
