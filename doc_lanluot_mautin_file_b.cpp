#include<stdio.h>
#pragma pack(1)
typedef struct{
	char maso[7];
	char hoten[41];
	char ngaysinh[11];
	float diem1, diem2, diem3;
}HOCSINH;
void DocVaInDanhSachHocSinh(char *tentaptin){
	int  n=0;
	HOCSINH hs; //bien dung de luu lan luot cac tap phan tu HOCSINH trong file
	FILE *taptin=fopen(tentaptin, "rb");
	if(taptin!=NULL){
		while(!feof(taptin)){
			if(fread(&hs,sizeof(HOCSINH),1,taptin)<=0) break;
			else{
				n++;
				printf("%5d %6s %20s %10s\n",n,hs.maso,hs.hoten,hs.ngaysinh);
		
			}
		}
		fclose(taptin);
		
	}
}
int main(){
	DocVaInDanhSachHocSinh("dshs.txt");
	return 1;
}
