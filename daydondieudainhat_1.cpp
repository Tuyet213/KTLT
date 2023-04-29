#include<stdio.h>
int a[30];
int n;
int t[30];
int d[30];

void docfile(){
	FILE *f=fopen("mangnguyen.txt","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
		fclose(f);
	}
}

void dynamic(){
	for(int i=1;i<=n;i++){
		d[i]=1;
		t[i]=0; 
	} 
	
	for(int i=1;i<=n;i++){
		int lmax=0;
		for(int j=1;j<i;j++){
			if(a[i]>a[j]&&lmax<d[j]){
				lmax=d[j];
				t[i]=j;
			} 
			d[i]=lmax+1;
		} 
	} 
	
	int dainhat=d[1];
	int indexmax;
	for(int i=1;i<=n;i++){
		if(d[i]>dainhat){
			dainhat=d[i];
			indexmax=i;
		}
	}
	
	int l[30];
	int k=1;
	while(indexmax>0){
		l[k++]=indexmax;
		indexmax=t[indexmax];
	}
	printf("Do dai day: %d\n",dainhat);
	for(int i=k-1;i>0;i--) printf("%d ",a[l[i]]);
} 

int main(){
	docfile();
	dynamic();
	return 1;	 
} 

