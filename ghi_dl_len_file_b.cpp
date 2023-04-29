#include<stdio.h>
#pragma pack(1)
typedef struct{
	char maso[7];
	char hoten[41];
	char ngaysinh[11];
	float diem1, diem2, diem3;
}HOCSINH;
void TaoDanhSachHocSinh(char *tentaptin){
	HOCSINH dshs[]={{"111111","Lam Vinh","23/07/2003",0,0,0},
					{"111112","Lam Vu","23/07/2004",0,0,0},
					{"111113","Lam Vy","23/07/2005",0,0,0},
					{"111114","Lam Va","23/07/2006",0,0,0},
					{"111115","Lam Van","23/07/2007",0,0,0}};
	int n=sizeof(dshs)/sizeof(dshs[0]);
	FILE* taptin=fopen(tentaptin,"wb");
	if(taptin!=NULL){
		fwrite(dshs,sizeof(HOCSINH),n,taptin); //n*sizeof(HOCSINH)==>ghi het tat ca cac gia tri trong dshs[] 
		fclose(taptin);
	}				
	else printf("Khong the mo tap tin.\n");	
}
int main(){
	TaoDanhSachHocSinh("dshs.txt");
	return 1;
}
