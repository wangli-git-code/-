#include<bits/stdc++.h>
using namespace std;
const int max_word = 1024;
char token[1024];
char in[1024];
FILE *fin,*fout;
int cnt = 0,token_num = 0;
int row = 1;
int flag = 0;
char ch;
char keyWord[7][33] = {"BEGIN","END","FOR","IF","THEN","ELSE"};
char keyWord1[7][33] = {"Begin","End","For","If","Then","Else"};

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
		char a[1024];
		for(int j=0;j<1024;j++) a[j]=0;
				strcat(a,"Ident(");
                strcat(a,token);
                strcat(a,")");
		return a;
	}
	else if(ch >= '0' && ch <= '9'){
		while(ch >= '0'&& ch <= '9'){
			token[token_num++] = ch;
			ch = getc(fin);
		}
		char a[1024];
		for(int j=0;j<1024;j++) a[j]=0;
				strcat(a,"Int(");
                strcat(a,token);
                strcat(a,")");
		return a;
	}
	else{
		token[token_num++] = ch;
		switch(ch){
			case '(': ch = getc(fin); return "LParenthesis";
			case ')': ch = getc(fin); return "RParenthesis";
			case '+': ch = getc(fin); return "Plus";
			case '*': ch = getc(fin); return "Star";
			case ',': ch = getc(fin); return "Comma";
			case ':':{
				ch = getc(fin);
				if(ch == '='){
					token[token_num++] = ch;
					ch = getc(fin);
					return "Assign";
				}
				else{
					return "Colin";
				}
			}
			default: ch = getc(fin); return NULL;
		}
	}
}

int main(){
	fin = fopen("compiler.txt","r");
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
