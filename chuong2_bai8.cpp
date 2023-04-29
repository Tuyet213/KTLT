#include<stdio.h>
void NhapMatran(float a[][100], int &n, int &m){
	printf("Nhap so dong, cot: "); scanf("%dx%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%f",&a[i][j]);
		}
	} 
} 

void XuatMatran(float a[][100], int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%f ",a[i][j]);
		}
		printf("\n");
	}
}

float Min(float a[][100], int n, int m){
	float min=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]<min) min=a[i][j];
		}
	} 
	return min;
}

int main(){
	float a[100][100];
	int n,m;
	NhapMatran(a,n,m);
	XuatMatran(a,n,m);
	printf("%f",Min(a,n,m));
	return 1;
}













