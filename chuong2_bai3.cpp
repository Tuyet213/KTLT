#include<stdio.h>
#include<conio.h>
int x;
void tanggiam(int &x, int y){
	printf("\nx=%3d,y=%3d",x,y);
	x=x+2;
	if(y>0){
		y=y-1;
		tanggiam(x,y);
	}	
	printf("\nx=%3d,y=%3d",x,y);
}
int main(){
	x=5;
	tanggiam(x,x);
	getch();
	return 0;
	
}
