#include<stdio.h>
#include<string.h>
#include<ctype.h>
#pragma pack(1)
#define Maxtu 1024
#define Maxch 64
typedef struct{
	char word[Maxch];
	int count;
}Word;

void countWord(FILE *f, Word Arr[], int &n){
	char ch;
	char word[Maxch]="";
	int len=0;
	n=0;
	while(!feof(f)){
		ch=fgetc(f);
	//	if(ch==EOF) break;
	//	ch=tolower(ch);
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'){
			word[len++]=ch;
		}
		else{
			word[len]=NULL;
			if(word[0]!=NULL){//////////////////////////////notice
				strcpy(Arr[n++].word,word);
				len=0;
				word[0]=NULL;
			}
			
		}
		
	}
	printf("So tu trong file la %d\n",n);
	for(int i=0;i<n;i++){
		printf("%s\n",Arr[i].word);
	}
}

int main(){
	FILE *f=fopen("BB.txt","rt");
	int n;
	Word Arr[Maxtu];
	countWord(f, Arr,n);
	fclose(f);	 
} 
