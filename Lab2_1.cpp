#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

void Doc_File(int a[],int &n);
void Xuat_DS(int a[],int n);
bool KT_CP(int x);//kiem tra x co la so chinh phuong kg?
void Ghi_File(int a[],int n);
//
int main(){
	int a[MAX],n;
///	Doc_File(a,n);
//	Xuat_DS(a,n);
//	Ghi_File(a,n);
	srand((int)time(0));
	int x = rand()%1000;
	printf("%d",x);
	return 0;
}
//doc noi dung Lab2_1.inp vao mang a
void Doc_File(int a[],int &n){	
	FILE *f=fopen("Lab2_1.txt","r");
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
//xuat day so ra man hinh
void Xuat_DS(int a[],int n){
	int i;
	for(i=0; i<n; i++)
		printf("%5d",a[i]);
}
//kiem tra so chinh phuong
bool KT_CP(int x){
	int y = sqrt(x);
	if(y*y == x)
		return true;
	return false;
}
//ghi cac so chinh phuong cua a[] vao file
void Ghi_File(int a[],int n){
	FILE *f=fopen("Lab2_1.out","w");
	if(f==NULL)
		printf("Err!");
	else{
		int i;
		bool kt=false;//gia su kg co so cp trong a[]
		for(i=0;i<n;i++)
			if(KT_CP(a[i])){
				fprintf(f,"%d\t",a[i]);
				kt=true;//co so cp trong a[]
			}
		//neu kg co so cp thi ghi -1 vao file
		if(kt==false)		
			fprintf(f,"%d",-1);
	}
}

	

