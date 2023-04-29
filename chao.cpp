#include<stdio.h>
#include<stdlib.h>

int main(){
 float a[10]={1.5,4.5,6, 5.6, -2.3};
 int dem=0;
 float S=0;
 for(int i=0;i<5;i++){
 	if(a[i]>0){
 		dem++;
 		S+=a[i];
	 }
 }	
 printf("%f",S/dem);
 return 1;
}

