#include<stdio.h>
#define SWAP(a,b,temp){temp=a;a=b;b=temp;}

float w[]={50,70,90,40};
float v[]={3,7,2,1};
float p[30];
int M=20;
int l[30]; 
int n=sizeof(w)/sizeof(w[0]);

void hoanvi(float &a, float &b){
	float temp=a;
	a=b;
	b=temp; 
} 

void greedy(){
	for(int i=0;i<n;i++) p[i]=v[i]/w[i];
	for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(p[i]<p[j]){
		hoanvi(p[i],p[j]);
		hoanvi(v[i],v[j]);
		hoanvi(w[i],w[j]);
	}
	int T=M;
	int i=0; //vat thu i
	while(T>0 && i<n){
		//chon ung vien tot nhat
		if(T>=w[i]){
			l[i]++;
			T-=w[i];
		} 
		i++;
	}	
}

void in(){
	for(int i=0;i<n;i++) {
		if(l[i]==1) printf("Vat có gia tri %f nang %f\n",v[i],w[i]); 
	}
} 

int main(){
	greedy();
	in();
	return 1; 
} 

