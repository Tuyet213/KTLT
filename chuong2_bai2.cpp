#include<stdio.h>
int f(int n){
//	if(n==0)  return 0;
//	else if(n==1) return 1;
	if(n<=1) return n;
	else{
		int val=4*f(n-1);
		val=val-3*f(n-2);
		val+=2;
		return val;
	}
	
}
int main(){
	printf("%d %d",f(2),f(3));
}
