#include<stdio.h>
int a[]={5,7,10,9,2,12};
int n=sizeof(a)/sizeof(a[0]);
int t[30];
int P=12;
void in(){
	int sum=0;
	for(int i=0;i<n;i++) if(t[i]==1) sum+=a[i];
	if(sum==P){
		printf("\n");
		for(int i=0;i<n;i++) if(t[i]==1) printf("%d ",a[i]);
 }

}

void thu(int i){
	for(int j=0;j<=1;j++){
		t[i]=j;
		if(i==n-1) in();
		else thu(i+1);
	}
}

int main(){
	thu(0);
	return 1;
}
