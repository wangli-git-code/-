#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
const int max_word = 1024;
char token[1024];
char in[1024];
char s[1024];
FILE *fin,*fout;
int cnt = 0,token_num = 0;
int row = 1;
int flag = 0;
char ch;
char keyWord[7][33] = {"BEGIN","END","FOR","IF","THEN","ELSE"};
char keyWord1[7][33] = {"Begin","End","For","If","Then","Else"};
char a1[20]="LParenthesis";
char a2[20]="RParenthesis";
char a3[20]="Plus";
char a4[20]="Star";
char a5[20]="Comma";
char a6[20]="Assign";
char a7[20]="Colon";
char a8[20]="Unkonwn";
void init_token(){
	int i;
	for(i = 0;i < 1024;i++){
		token[i] = 0;
	}
}

char* judge_token(){
	init_token();
	if(flag == 0){
		ch = getc(fin);
	}
	flag = 1;
	while(ch == ' ' || ch == '\t' || ch == '\n'){
		if(ch == '\n'){
			row++;
		}
		ch=getc(fin);
	}
	token_num = 0;
	if((ch>='a' && ch <= 'z') || (ch >= 'A' &&ch <= 'Z')){
		while((ch>='a' && ch <= 'z') || (ch >= 'A' &&ch <= 'Z') || (ch >= '0' && ch <= '9')){
			token[token_num++] = ch;
			ch = getc(fin);
		}
		token[token_num++] = '\0';
		for(int i = 0;i <7;i++){
			if(strcmp(token,keyWord[i]) == 0){
				return keyWord1[i];
			}
		}
		for(int j=0;j<1024;j++) s[j]=0;
				strcat(s,"Ident(");
                strcat(s,token);
                strcat(s,")");
		return s;
	}
	else if(ch >= '0' && ch <= '9'){
		while(ch >= '0'&& ch <= '9'){
			token[token_num++] = ch;
			ch = getc(fin);
		}
		for(int j=0;j<1024;j++) s[j]=0;
				strcat(s,"Int(");
				int k=0;
				while(token[k]=='0') k++;
                strcat(s,token+k);
                strcat(s,")");
		return s;
	}
	else{
		token[token_num++] = ch;
		switch(ch){
			case '(': ch = getc(fin); return a1;
			case ')': ch = getc(fin); return a2;
			case '+': ch = getc(fin); return a3;
			case '*': ch = getc(fin); return a4;
			case ',': ch = getc(fin); return a5;
			case ':':{
				ch = getc(fin);
				if(ch == '='){
					token[token_num++] = ch;
					ch = getc(fin);
					return a6;
				}
				else{
					return a7;
				}
			}
			default: ch = getc(fin); cout<<a8<<endl;return NULL;
		}
	}
}

int main(int argc, char **argv){
	fin = fopen(argv[1],"r");
	char *temp=NULL;
	while(1){
		temp = judge_token();
		if(temp==NULL){
			return 0;
		}
		cout<<temp<<endl;
	}
	return 0;
}
