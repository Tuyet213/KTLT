#include<stdio.h>
#define Max 100

void GhiFile(char *tentaptin, int &n){
	FILE *f=fopen(tentaptin,  "wt");
	if(f!=NULL){
		fprintf(f,"Day cac do thuc: \n");
		printf("Nhap gia tri n: ");
		//int n;
		scanf("%d",&n);
		fprintf(f,"%d\n",n);
		float a;
		for(int i=0;i<n;i++){
			printf("Phan tu thu %d: ",i+1);
			scanf("%f",&a);
			fprintf(f,"%f ",a);
		}
		fclose(f);
	}
	else printf("Khong mo file duoc.\n");
}

void DocFile(char *tentaptin, float a[], int n){
	FILE *f=fopen(tentaptin,"rt");
	if(f!=NULL){
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++){
			fscanf(f,"%f",&a[i]);
		}
		fclose(f);
	}
	else printf("Khong mo duoc file.\n");
}

void HoanVi(float &a, float &b){
	float temp=a;
	a=b;
	b=temp;
}

void phtu_lonthu2(char *tentaptin, float a[], int n){
	DocFile(tentaptin,a,n);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) HoanVi(a[i],a[j]);
		}
	}
	printf("Phan tu lon thu 2 trong day la %f",a[n-2]);
	
}

void second_max(char *tentaptin, int n){
	FILE *f=fopen(tentaptin,"rt");
	if(f!=NULL){
		fscanf(f,"%d",&n);
		float max, m2, temp;
		fscanf(f,"%f",&max);
		fscanf(f,"%f",&m2);
		for(int i=0;i<n;i++){
			fscanf(f,"%f",&temp);
			if(temp>max) {
				m2=max;
				max=temp;
			}
		}
		printf("So lon thu hai la %f",m2);
		fclose(f);
	}
	else printf("Khong mo duoc file.\n");
}


int main(){
	float a[Max];
	int n;
	char tentaptin[]="DAYSO.txt";
	GhiFile(tentaptin,n);
//	phtu_lonthu2(tentaptin,a,n);
	second_max(tentaptin,n);
	return 1;
}

