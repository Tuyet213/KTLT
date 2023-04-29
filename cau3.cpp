#include<stdio.h>

void DocFile(char *tentaptin, float a[], int &n){
	FILE *f=fopen(tentaptin, "rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f,"%d",n);
		for(int i=0;i<n;i++){
			fscanf(f,"%f",&a[i]);
		}
		fclose(f);
	}
}

int dem(float a[], int n){
	if(n==0) return 0;
	if(a[n-1]>=1.55&&a[n-1]<=1.7) return dem(a,n-1)+1;
	return dem(a,n-1);
}
void GhiFile(char *tentaptin, float a[], int n){
	
	FILE *f=fopen(tentaptin,"wt");
	if(f==NULL) printf("Khong mo duoc file.");
	else {
		int t=dem(a,n);
		fprintf(f,"%d",t);
		fclose(f);
	}
}

int main(){
	char *tentaptin1="chieucao.txt";
	char *tentaptin2="soluong.txt";
	float a[51];
	int n;
	DocFile(tentaptin1,a,n);
	GhiFile(tentaptin2,a,n);
	return 1;
}
