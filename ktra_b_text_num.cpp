#include<stdio.h>
int main(){
	FILE *f=fopen("Tuyet.txt","wb");
	float a=12.45; 
	if(f!=NULL){
		fwrite(&a,sizeof(a),1,f);
		fclose(f); 
	} 
	else printf("Khong mo duoc file.");
	return 1; 
} 
