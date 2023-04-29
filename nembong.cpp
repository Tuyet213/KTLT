#include<stdio.h>
int t[30];
int x[30];
int n;
int k;
int dem=0;

int ktra1(){
	for(int i=0;i<n-1;i++) if(t[i]==t[i+1]&&t[i]==0) return 0;
	return 1;
}

int ktra2(){
	int s=0;
	for(int i=0;i<n;i++) if(t[i]==1) s++;
	return s;
}

void in(){
	if(ktra1()&&ktra2()>=k){
		dem++;
		FILE *f=fopen("nembong.txt","r+t");
		if(f==NULL) printf("Khong mo duoc file");
		else{
			fseek(f,0,SEEK_SET);
			fprintf(f,"%d",dem);
			fseek(f,0,SEEK_END);
			fprintf(f,"\n");
			for(int i=0;i<n;i++) {
				if(t[i]) fprintf(f,"x");
				else fprintf(f,"_");
			}
			
			fclose(f);
		}
	}
	
}

void thu(int i){
	for(int j=0;j<=1;j++){
		t[i]=j;
		if(i==n-1) in();
		else thu(i+1);
		t[i]=0;
	}
}

int main(){
	n=4;
	k=5;
	thu(0);
	if(dem==0){
		FILE *f=fopen("nembong.txt","r+t");
		if(f==NULL) printf("Khong mo duoc file");
		else{
			fprintf(f,"-1");
			fclose(f);
		}
	}
	return 1;
}
