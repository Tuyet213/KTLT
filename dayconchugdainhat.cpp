#include<stdio.h>

int a[]={0,1,2,4,9,8,7,2};
int b[]={0,3,1,2,3,5,7,2};
int l[30][30];
int n=sizeof(a)/sizeof(a[0]);
int m=sizeof(b)/sizeof(b[0]);

int main(){
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i]==b[j])  l[i][j]=l[i-1][j-1]+1;
			else{
				if(l[i][j-1]>l[i-1][j]) l[i][j]=l[i][j-1];
				else l[i][j]=l[i-1][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) printf("%d ",l[i][j]);
		printf("\n");
	}
	printf("\n");
	int i=n; int j=m;
	while (i>0){
		if(a[i]==b[j]) {
			printf("%d ",a[i]);
			i--;
			j--;
		}
		else{
			if(l[i-1][j]>l[i][j-1]) i--;
			else j--;
		}
	}
	return 1;
}
