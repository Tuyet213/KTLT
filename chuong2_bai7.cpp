//#include<stdio.h>
//#define NUMBER 212
//int main(){
//	printf("%d",NUMBER);
//	#undef NUMBER
//		printf("%d",NUMBER);
//	return 0;
//}



#include<stdio.h>
#define NUMBER 212
int main(){
	printf("%d\n",NUMBER);
	#undef NUMBER
	int NUMBER=100; 
	printf("%d",NUMBER);
	return 0;
}
