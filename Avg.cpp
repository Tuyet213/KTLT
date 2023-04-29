#include<stdio.h>
#include<stdlib.h>

int main(int c, char *a[]){
	if(c>=4&&c<=31){
		float S=0;
		int dem=0;
		for(int i=1;i<c;i++){
			float tam=atof(a[i]);
			if(tam>0){
				dem++;
				S+=tam;
			}
		}
		if(dem>0) printf("Avg: %.1f",S/dem);
		else printf("Khong co so thuc duong nao.");
	}
	else printf("Loi!!");
}
