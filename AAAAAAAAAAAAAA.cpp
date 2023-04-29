#include<stdio.h>

void DocFile(char *tentaptin, float a[], int &n){
	FILE *f = fopen(tentaptin, "rt");
	if(f == NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f, "%d", &n);
		if(n >= 8 && n <= 50){
			for(int i = 0; i < n; i++)
				fscanf(f, "%f", &a[i]);
			fclose(f);
		}
		else {
			printf("So luong sinh vien khong thoa.");
			fclose(f);
			return ;
		}
	}
} 

float tim_diem(float a[], int n){
	if(n == 1 && a[0] > 7) return a[0];
	if(n == 1 && a[0] <= 7 ) return 0;
	if(a[n - 1] > 7 && (a[n - 1]) > tim_diem(a, n - 1)) return a[n - 1];
	return tim_diem(a, n - 1);
}

void GhiFile(char *tentaptin, float a[], int n){
	FILE *f = fopen(tentaptin,"wt");
	if(f == NULL) printf("Khong mo duoc file.");
	else{
		float diemhb = tim_diem(a, n);
		if(diemhb > 7) fprintf(f, "Mark: %.1f", diemhb);
		else fprintf(f, "-1");
		fclose(f);
	}
}

int main(){
	char *tentaptin1 = "HuynhThiNgocTuyet.inp";
	char *tentaptin2 = "HuynhThiNgocTuyet.out";
	float a[51];
	int n;
	DocFile(tentaptin1, a, n);
	GhiFile(tentaptin2, a, n);
	return 1;
}
