#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
char token[1030];
char ans[1030];
int op[6][6] = {{2,1,1,1,2,2},{2,2,1,1,2,2},{2,2,-1,-1,2,2},{1,1,1,1,0,-1},{2,2,-1,-1,2,2},{1,1,1,1,-1,-1}};
//+ * i ( ) #
FILE *fin,*fout;
int cnt=0;
int p=-1;
int q;
int s=0;
char a;
char b;
char c;
char d,ch;
int i,j,k;
char e;
int h[200];
void init_token(){
	int i;
	for(i = 0;i < 1024;i++){token[i] = 0;}
	cnt=0;
	ch=getc(fin);
	while((ch!='\r')&&(ch!='\n')){
		token[cnt++]=ch;
		ch=getc(fin);
	}
	token[cnt++]='#';
}

int main(int argc, char **argv){
	fin = fopen(argv[1],"r");
	init_token();
	h['+']=0;
	h['*']=1;
	h['i']=2;
	h['(']=3;
	h[')']=4;
	h['#']=5;
	ans[++p]='#';
	
	while(true){
		q=p;
		while(ans[q]=='n'){
			q--;
		}
		a=ans[q];
		b=token[s];
		if(op[h[a]][h[b]]==1||op[h[a]][h[b]]==0){
			ans[++p]=b;
			s++;
			printf("I%c\n",b);
		}
		else if(op[h[a]][h[b]]==2){
			if((a=='+'||a=='*')&&p==q){
				printf("RE\n");
				return 0;
			}
			while(true){
				int times=0;
				for(i=p;i>=0;i--){
					if(ans[i]!='n'&&times==0) {
						c=ans[i];
						times++;
					}
					else if(ans[i]!='n'&&times==1){
						d=ans[i];
						break;
					}
				}
				k=i;
				if(op[h[d]][h[c]]==0){
					for(j=i-1;j>=0;j--){
						if(ans[j]!='n') {
							e=ans[j];
						}
					}
					c=d;
					d=e;
					k=j;
				}
				else if(op[h[d]][h[c]]==1){
					break;
				}
				else if(op[h[d]][h[c]]==-1){
					printf("E\n");
					return 0;
				}
			}
			
			
			p=k+1;
			ans[p]='n';
			printf("R\n");
			if(p==1&&ans[0]=='#'&&ans[1]=='n'&&token[s]=='#'){
				return 0;
			}
		}
		else if(op[h[a]][h[b]]==-1){
			printf("E\n");
					return 0;
		}	
	}
	return 0;
}
