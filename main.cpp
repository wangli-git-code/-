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
int hash[200];
void init_token(){
	int i;
	for(i = 0;i < 1024;i++){token[i] = 0;}
	cnt=0;
	while((ch=getc(fin))!='\n'){
		token[cnt++]=ch;
	}
	token[cnt++]='#';
}

	
	
int main(int argc, char **argv){
	fin = fopen(argv[1],"r");
	init_token();
	hash['+']=0;
	hash['*']=1;
	hash['i']=2;
	hash['(']=3;
	hash[')']=4;
	hash['#']=5;
	ans[++p]='#';
	
	while(true){
		q=p;
		while(ans[q]=='n'){
			q--;
		}
		a=ans[q];
		b=token[s];
		if(op[hash[a]][hash[b]]==1||op[hash[a]][hash[b]]==0){
			ans[++p]=b;
			s++;
			printf("I%c\n",b);
		}
		else if(op[hash[a]][hash[b]]==2){
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
				if(op[hash[d]][hash[c]]==0){
					for(j=i-1;j>=0;j--){
						if(ans[j]!='n') {
							e=ans[j];
						}
					}
					c=d;
					d=e;
					k=j;
				}
				else if(op[hash[d]][hash[c]]==1){
					break;
				}
				else if(op[hash[d]][hash[c]]==-1){
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
//			else if(token[s]=='#'&&p!=1){
//				
//			}
		}
		else if(op[hash[a]][hash[b]]==-1){
			printf("E\n");
					return 0;
		}
			
	}

	
	return 0;
}
