//cai tui QHD
#include <stdio.h>
#define MAX(a,b)(a>b?a:b)
#define N 20

int v[N];//gia tri cua tung mon hang
int w[N];//trong luong tung mon hang
int n;
int p; //trong luong cai tui
int L[N][N];//bang luu tru ket qua cac buoc QHD

//
void Read_File(){
	FILE *f=fopen("balo.txt","r");
	if(f!=NULL){
		fscanf(f,"%d",&n);	
		fscanf(f,"%d\n",&p);	
		//doc gia tri cac do vat vao mang v		
		for (int i=1; i<=n; i++)
			fscanf(f,"%d\t",&v[i]);	
			
		//doc trong luong cac do vat vao mang w		
		for (int i=1; i<=n; i++)
			fscanf(f,"%d\t",&w[i]);					
	}	
	else printf("Khong mo duoc file.");
	fclose(f);	
}
//
void Dynamic(){
	for(int i=1;i<=n;i++)
	for (int j = 1; j <= p; j++)		
	   	if (w[i] <= j )
			L[i][j] = MAX(L[i-1][j],L[i-1][j-w[i]]+v[i]);	
		else
		    L[i][j] = L[i-1][j];   	 
}
//truy vet
void Track(){
	FILE *f=fopen("baloout.txt","w");
	if(f!=NULL){
		int j= p;
		for (int k=n; k>=0; k--)
			if (L[k][j] != L[k-1][j]) {
				fprintf(f,"Vat thu: %d, gia tri: %d, trong luong: %d\n",k,v[k],w[k]);
				j=j-w[k];
		}
		fclose(f);
	}
}
int main(){
	Read_File();
	//khoi tao
	for(int i=0;i<=n;i++)
		L[i][0]=0;
	for(int j=0;j<=p;j++)
		L[0][j]=0;
	Dynamic();
	//xuat ra bang gia tri
	for(int i=0;i<=n;i++){
		for(int j=0;j<=p;j++)
			printf("%5d",L[i][j]);
		printf("\n");
	}
	//truy vet
//	Track();
}
