#include<stdio.h>

int a[30];
int t[30];
int dem=0;
int s;
int n;

void DocFile(){
	FILE *f=fopen("lab4_3.inp", "rt");
	if(f==NULL) printf("Khong mo duoc file !");
	else{
		fscanf(f,"%d",&n);
		if(n>=30) return;
		fscanf(f,"%d",&s);
		for(int i=1;i<=n;i++) fscanf(f,"%d",&t[i]);
		fclose(f);
	}
}

void in(){
	int sum=0;
	for(int i=1;i<=n;i++) sum+=t[i]*a[i];
	if(sum==s){
		FILE *f=fopen("lab4_3.txt", "r+t"); //at
		if(f==NULL) printf("Khong mo duoc file!");
		else{
			dem++;
			fseek(f,0,SEEK_END);//bo
			for(int i=1;i<=n;i++)	if(a[i]==1)	fprintf(f,"(%d)%d	",i,t[i]);
			fprintf(f,"\n");
			fclose(f);
		}
	}
}

void ATM(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==n) in();
		else ATM(i+1);
	}
}

int main(){
	DocFile();
	ATM(1);
	if(dem==0){
		FILE *f=fopen("lab4_3.txt", "wt");
		if(f==NULL) printf("Khong mo duoc file!");
		else{
			fprintf(f,"-1");
			fclose(f);
		}
	}
	return 1;
}

