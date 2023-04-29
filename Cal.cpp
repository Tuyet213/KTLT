#include<stdio.h>
#include<stdlib.h>
float Calculator(float a, float b, char c){
	float r;
	switch(c){
		case '+': r= a+b; break;
		case '-': r =a-b; break;
		case '*': r =a*b; break;
		case '/': {
			if(b!=0) r= (float)a/b;
		//	else return 0;
		}
		return r;
	}
}
int main(int argc, char *argv[]){
	if(argc==4){
		float x = atof(argv[1]);
		float y = atof(argv[3]);
	// argv[2] la chuoi=> ket thuc la \n
	// gan qua char thi chi lay ky tu dau
		char c = *argv[2];
		printf("%f %c %f = %f", x, c, y, Calculator(x,y,c));
	}
	else
		printf("Nhap sai.");
}
