#include<stdio.h>
int h[30];//dung luong dia 
int n;
int M;
int t[30];//luu trang thai dia 
int dia;

void docfile(){
	FILE *f=fopen("ghidia.txt","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&M);
		for(int i=0;i<n;i++) fscanf(f,"%d",&h[i]);
		fclose(f);
	}	
} 

void ghifile(){
	FILE *f=fopen("ghidiaout.txt","wt");
	if(f==NULL) printf("Khong mo duoc file!");
	else{
		for(int i=1;i<dia;i++){
			for(int j=0;j<n;j++) {
				if(t[j]==i){
					fprintf(f,"%d ",h[j]);
				}
			}	
			fprintf(f,"\n");
		}
		fclose(f);
	}	
}

void sapxep(int a[],int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
}

void greedy(){
	sapxep(h,n);
	dia=1;		
	for(int i=0;i<n-1;i++){
		if(t[i]==0){
			t[i]=dia;
			int du=M-h[i];
			for(int j=i+1;j<n;j++){
				if(t[j]==0&&h[j]<=du){
					t[j]=dia;
					du=du-h[j];
				}
			}
		
		}
		dia++;
	}
}

int main(){
	docfile();
	greedy();
	ghifile();
	return 1;
}

