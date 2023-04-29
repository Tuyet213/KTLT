#include<stdio.h>
#include<conio.h>
void Change(int x, int &y){
	printf("\nx=%2d,y=%2d",x,y);
	x=x+1;
	y=y-1;
	if(x<5) Change(x,y);
	printf("\nx=%2d,y=%2d",x,y);
}
int main(){
	int a=2;
	Change(a,a);
	getch();
	return 0;
}
