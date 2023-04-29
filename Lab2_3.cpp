#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

void Ghi_File();
void Doc_File(int a[][MAX],int &n);
void Xuat_MT(int a[][MAX],int n);
//
int main(){
	int a[MAX][MAX],n;
	Ghi_File();
	Doc_File(a,n);
	Xuat_MT(a,n);
}
//
void Ghi_File(){
	FILE *f=fopen("Lab2_3.inp","w");
	if(f==NULL)
	 	printf("Err!");
	else{	
		int i,j,n,m;	
		printf("nhap so n:");
		scanf("%d",&n);
		fprintf(f,"%d\n",n);		
		//tao nxn so ngau nhien
		srand((int)time(0));
		for(i=0;i<n;i++){		
			for(j=0;j<n;j++){
				m=rand()%1000;  //tao 1 so ngau nhien
				fprintf(f,"%d\t",m);//ghi so m vao file
			}
			fprintf(f,"\n");//ghi dau xuong dong vao file
		}
		fclose(f);
	}
}
//
void Doc_File(int a[][MAX],int &n){
	FILE *f=fopen("Lab2_3.inp","r");
	if(f==NULL)
	 	printf("Err!");
	else{	
		int i,j;
		fscanf(f,"%d",&n);//doc n tu file vao chuong trinh
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fscanf(f,"%d",&a[i][j]);
		fclose(f);
	}
}
void Xuat_MT(int a[][MAX],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%8d",a[i][j]);
		printf("\n");//xuong hang
	}
		
}
