#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

void Doc_File(int a[],int &n);
void Xuat_DS(int a[],int n);
void Ghi_File_a();
float TBC(int a[],int n,int &c);
void SapXep(int a[],int n);
void Ghi_File_e(int a[],int n,int c);
//
int main(){
	int a[MAX],n,c;
	Ghi_File_a();//tao n so ngau nhien luu vao file
	Doc_File(a,n);
	Xuat_DS(a,n);
	Ghi_File_e(a,n,c);
}
//
void Doc_File(int a[],int &n){
	FILE *f=fopen("Lab2_2.inp","r");
	if(f==NULL)
		printf("Err!!!");
	else{
		fscanf(f,"%d",&n);
		int i;
		for(i=0; i<n; i++)
			fscanf(f,"%d",&a[i]);
		fclose(f);
	}
}
void Xuat_DS(int a[],int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
}
//tao n so ngau nhien ghi vao file
void Ghi_File_a(){
	FILE *f=fopen("Lab2_2.inp","w");
	if(f==NULL)
	 	printf("Err!");
	else{	
		int i,n,m;	
		printf("nhap so n:");
		scanf("%d",&n);
		fprintf(f,"%d\n",n);//ghi n vao file van ban sau do xuong dong
		srand((int)time(0));		
		for(i=0;i<n;i++){			
			m=rand()%1000;  //tao 1 so ngau nhien
			fprintf(f,"%d\t",m);//ghi so m vao file
		}
		fclose(f);
	}
}
//tinh va tra ve TBC cac phan tu le
float TBC(int a[],int n,int &c){
	int s=0;
	int i;
	c=0;
	for(i=0;i<n;i++)
		if(a[i]%2==1){
			s +=a[i];
			c++;
		}
	return (float)s/c;	
}
void SapXep(int a[],int n){
	int i,j,t;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
		if(a[i]>a[j]){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
}
void Ghi_File_e(int a[],int n,int c){
	FILE *f=fopen("Lab2_2.out","w");
	if(f==NULL)
	 	printf("Err!");
	else{
		fprintf(f,"TBC: %f\n",TBC(a,n,c))	;
		fprintf(f,"So luong so le: %d\n",c);
		//ghi cac phan tu a[] sau sap xep vao file
		SapXep(a,n);
		int i;
		for(i=0;i<n;i++)
			fprintf(f,"%d\t",a[i]);
	}
}

