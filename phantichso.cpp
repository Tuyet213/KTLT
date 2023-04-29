#include<stdio.h>
int x[20];
int s[20];
int n=5;

void in(int k){
	FILE *f=fopen("phantichso.txt","at");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		for(int i=1;i<k;i++) fprintf(f,"%d + ",x[i]);
		fprintf(f,"%d\n",x[k]);
		fclose(f);
	}	
}

int ptso(int i){
	for(int j=x[i-1];j<=n-s[i-1];j++){//khi nao co gan trang thai thi mois tra ve trang thai ban dau
		x[i]=j;                        //bai nay la su tang tuyen tinh
		s[i]=s[i-1]+j;
		if(s[i]==n) in(i);
		else ptso(i+1);
	}
}

int main(){
	x[0]=1;
	s[0]=0;
	ptso(1);
	return 1;
}
