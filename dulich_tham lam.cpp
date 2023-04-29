#include<stdio.h>

int n;
int cp[30][30];
int x[30];
int t[30];
int sum=0;

void docfile(){
	FILE *f=fopen("dulich.txt","rt");
	if(f==NULL) printf("Khong mo duoc file !");
	else{
		fscanf(f,"%d",&n);
		if(n<=0||n>30) printf("So luong thanh pho khong dat yeu cau.");
		else{
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) fscanf(f,"%d",&cp[i][j]);
		}
		fclose(f);
	}
}


void greedy(){
	t[1]=1;
	x[1]=1;
	int i=2;
	while(i<=n){
		int max=10000;
		for(int j=2;j<=n;j++){
			if(t[j]==0&&cp[x[i-1]][j]<max){
				max=cp[x[i-1]][j];
				x[i]=j;
			}
		}
		sum=sum+max;
		t[x[i]]=1;
		i++;
	}
}


void ghifile(){
	FILE *f=fopen("dulichout.txt","wt");
	if(f==NULL) printf("khong mo duoc file");
	else{
		for(int i=1;i<=n;i++) fprintf(f,"TP%d-->",x[i]);
		fprintf(f,"TP1");
		fprintf(f,"\nTong chi phi la: %d",sum+cp[x[n]][1]);
	}
}

int main(){
	docfile();
	greedy();
	ghifile();
	return 1;
}
