#include<stdio.h>

int a[30];
int n;
int t[30];
int dem=0;
int s=40;
void docfile(){
	FILE *f=fopen("thoigian.txt","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f,"%d",&n);
		if(n<2||n>20){
			printf("So luong bai khong thoa yeu cau.");
			return;
		}
		else{
			for(int i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}

void sapxep(int a[], int n){
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
}

void greedy(){
	int i=1;
	while(i<=n){
		if(a[i]<=s){
			dem++;
			t[i]=1;
			s=s-a[i];
		}
		i++;
	}
}

void in(){
	FILE *f=fopen("thoigianout.txt","wt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		if(dem==0) fprintf(f,"Khong thuc hien duoc");
		else{
			fprintf(f,"%d\n",dem);
			for(int i=1;i<=n;i++)
				if(t[i]==1) fprintf(f,"%d ",a[i]);
		}
		fclose(f);
	}
}

int main(){
	docfile();
	sapxep(a,n);
	greedy();
	in();
	return 1;
}








