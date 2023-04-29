#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct hp{
	char ten[255];
	char mahp[255];
	int stc;
};

typedef struct hp HocPhan;

HocPhan *a;
int n;
 
void DocFile(){ //char *tentaptin, HocPhan *a, int &n
	FILE *f=fopen("hp.tuyet", "rt");
	if(f==NULL) printf("Errr!!!");
	else{
		fscanf(f,"%d\n",&n);
		char tam[255];
		a =(HocPhan *)malloc(n*sizeof(HocPhan)); 
		for(int i=0;i<n;i++){
			fgets(a[i].mahp,255,f);
			fgets(a[i].ten,255,f);
			
			fgets(tam,255,f);
			a[i].stc=atoi(tam);
		}
		fclose(f);
	} 
} 

void Xuat(){//HocPhan *a, int n
	printf("So hoc phan: %d\n",n);
	for(int i=0;i<n;i++){
		printf("%s",a[i].mahp);
		printf("%s",a[i].ten);
		printf("%d\n",a[i].stc);
	}
}

void Nhapthem(){
	FILE *f=fopen("hp.tuyet", "r+t");
	if(f==NULL) printf("Err!!!!");
	else{
		n++;
		fprintf(f, "%d",n);
		HocPhan them;
		fseek(f,0,SEEK_END);
		printf("Nhap mahp: ");
		fflush(stdin);
		gets(them.mahp);
		fprintf(f,"\n");
		fputs(them.mahp,f);
		printf("Nhap ten: ");
		fflush(stdin);
		gets(them.ten);
		fprintf(f,"\n");
		fputs(them.ten,f);
		printf("Nhap so tin chi: ");
		fflush(stdin);
		scanf("%d",&them.stc);
		fprintf(f,"\n");
		fprintf(f,"%d",them.stc);
		fclose(f);
	}
}

int main(){
//	HocPhan *a;
//	int n;
//	char *tentaptin="hp.tuyet";
	DocFile();//tentaptin,a,n
	Xuat();
	Nhapthem();
	DocFile();
	Xuat();
	return 1;
}

















