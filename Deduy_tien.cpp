#include<stdio.h>
float Tien(int nam, float a, float b, float X){
	if(nam==0) return X;
	if(nam%10==0) return Tien(nam-1,a,b,X*(1+b));
	return Tien(nam-1,a,b,X*(1+a));
}

int main(){
	printf("%f",Tien(10,0.1,0.2,5));
	return 1;
}
