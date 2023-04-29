#include<stdio.h>

int n;
int cp[31][31];
int x[31];
int t[31];
int max=10000;
int l[31];
int sum=0; 


void DocFile(){
	FILE *f=fopen("dulich.txt","rt");
	if(f==NULL) printf("khong mo duoc file!");
	else{
		fscanf(f,"%d",&n);
		if(n<0||n>=30) printf("So luong thanh pho khong thoa");
		else 
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) fscanf(f,"%d",&cp[i][j]);
		fclose(f);
	}
}

void dulich(int i){//////quay lui la thay cho vong lap for voi muc dich tim kq cho tung nghiem thanh phan 
	for(int j=2;j<=n;j++){
		if(t[j]==0){
			t[j]=1;
			x[i]=j;
			sum+=cp[x[i-1]][j]; 
			if(i==n){
				if(sum<max){
					for(int k=1;k<=n;k++) l[k]=x[k];
					max=sum;
				}
			}
			else dulich(i+1);
			t[j]=0;
			sum=sum-cp[x[i-1]][j]; 
		}
	}
	
}

void GhiFile(){
	FILE *f=fopen("dulichout.txt","wt");
	if(f==NULL) printf("khong mo duoc file");
	else{
		for(int i=1;i<=n;i++) fprintf(f,"TP%d-->",l[i]);
		fprintf(f,"TP1");
		max=max+cp[l[n]][1]; 
		fprintf(f,"\nTong chi phi: %d",max);
		fclose(f);
	}
}

int main(){
	x[1]=1;
	t[1]=1;
	DocFile();
	dulich(2);
	GhiFile();
	return 1;
}











