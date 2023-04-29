#include<stdio.h>
void EncodingFile(char *fname1, char *fname2, unsigned char Key[], int n){
	FILE *fp1=fopen(fname1, "rb");
	FILE *fp2=fopen(fname2, "rb");
	if(fp1!=NULL&&fp2!=NULL){
		int i=0;
		unsigned short markbytes=0xFEFF;
		fwrite(&markbytes,2,2,fp2);
		while(!feof(fp1)){
			int ch=fgetc(fp1);
			if(ch!=EOF){
				ch=((unsigned char)ch)^Key[i];
				fputc(ch,fp2);
			}
			i++;
			if(i>=n) i=0;
		}
		fclose(fp1);
		fclose(fp2);
	}
}
int main(){
	unsigned char MyKey[]="SIMPLE KEY";
	int n=sizeof(MyKey)-1;
	EncodingFile("DSHS.txt","DSHSENCODED.txt",MyKey,n);
	return 1;
}
