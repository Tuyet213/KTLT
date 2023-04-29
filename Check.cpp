#include<stdio.h>
#include<stdlib.h>

int main(int c, char *a[]){
	if(c >= 3 && c <= 31){
		for(int i = 1; i < c - 1; i++){
			float x = atof(a[i]);
			float y = atof(a[i+1]);
			if(x > y){
				printf("Day khong tang dan");
				return 1;
			}
		}
		printf("Day tang dan");
		return 1;
	}
	else printf("Loi!!!!");
}
