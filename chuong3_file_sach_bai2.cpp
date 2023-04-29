#include<stdio.h>
#include<stdlib.h> //su dung ham sinh so ngau nhien
#define Max 1000

void GhiFile(char *tentaptin){
	FILE *f=fopen(tentaptin,"wt");
	if(f!=NULL){
		int n=1000/10;
		int a;
		for(int i=1;i<=n;i++){
			for(int i=0;i<10;i++) {
				a=rand();
				fprintf(f,"%15d",a);
			}
			fprintf(f,"\n");
		}
		fclose(f);
	}	
	else printf("Khong mo duoc file.\n");
}

void DocFile(char *tentaptin, int a[Max], int &n){
	FILE *f=fopen(tentaptin,"rt");
	if(f!=NULL){
		n=Max;
		for(int i=0;i<n;i++){
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
	else printf("Khong mo duoc file.\n");
}

void HoanVi(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void SapXep(char *tentaptindoc, char *tentaptinghi, int a[Max], int n){
	DocFile(tentaptindoc,a,n);
	FILE *f=fopen(tentaptinghi,"wt");
	if(f!=NULL){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++) 
				if(a[i]>a[j]) HoanVi(a[i],a[j]);
		}
		for(int i=0;i<n;i++){
			fprintf(f,"%d ",a[i]);
		}
		fclose(f);
	}
	else printf("Khong mo duoc file.\n");
}

int main(){
	char in[]="SONGUYENINP.txt";
	char out[]="SONGUYENOUTP.txt";
	int a[Max];
	int n;
	GhiFile(in);
	SapXep(in, out, a, n);
	return 1;
}

