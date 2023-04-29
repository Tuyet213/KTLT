#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
////////neu dung tro cho mang thi nen khai bao toan cuc va cap phat dong cho no (khong tryen vao tham so cua ham)
 
///////neu dung mang thi khong can cap phat dong, duoc truyb=en vao tham so ham
 
struct hp{
	char ten[255];
	char mahp[255];
	int stc;
};

typedef struct hp HocPhan;

//HocPhan *a;
//int n;
 
void DocFile( HocPhan a[], int &n){ //char *tentaptin, HocPhan *a, int &n
	FILE *f=fopen("hp.tuyet", "rt");
	if(f==NULL) printf("Errr!!!");
	else{
		fscanf(f,"%d\n",&n);
		char tam[255];
	//	a =(HocPhan *)malloc(n*sizeof(HocPhan)); 
		for(int i=0;i<n;i++){
			fgets(a[i].mahp,255,f);
			fgets(a[i].ten,255,f);
			
			fgets(tam,255,f);
			a[i].stc=atoi(tam);
		}
		fclose(f);
	} 
} 

void Xuat(HocPhan a[], int n){//HocPhan *a, int n
	printf("So hoc phan: %d\n",n);
	for(int i=0;i<n;i++){
		printf("%s",a[i].mahp);
		printf("%s",a[i].ten);
		printf("%d\n",a[i].stc);
	}
}

void Nhapthem(HocPhan a[], int &n){
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
	HocPhan a[10];
	int n;
//	char *tentaptin="hp.tuyet";
	DocFile(a,n);//tentaptin,a,n
	Xuat(a,n);
	Nhapthem(a,n);
	DocFile(a,n);
	Xuat(a,n);
	return 1;
}

















