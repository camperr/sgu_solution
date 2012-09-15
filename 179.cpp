#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char sym[100007];
bool check(int si){
	int lb,rb;
	lb=rb=0;
	int i;
	for(i=0;i<si;i++){
		if(sym[i]==')') rb++;
		else lb++;
	}
	return lb==rb;
}
int main(){
	int i,j,k;
	//freopen("in.txt","r",stdin);
	scanf("%s",sym);
	int si=strlen(sym);
	if(!check(si)){
		printf("No solution\n");
		return 0;
	}
	int findSolution=false;
	int lb=0;
	int fl=0;
	for(i=0;i<si;i++){
		if(lb && sym[i]=='('){
			fl=i+1;
			findSolution=true;
		}
		if(sym[i]=='(') lb++;
		else lb--;
	}
	if(fl) sym[fl-1]=')';
	//printf("%d\n",fl);
	int leftBr=si/2;
	int rightBr=si/2;
	for(i=0;i<fl;i++){
		if(sym[i]=='(') {
			leftBr--;
		}			
		else rightBr--;
	}
	if(!findSolution) printf("No solution\n");
	else {
		for(i=0;i<leftBr;i++) sym[fl++]='(';
		for(i=0;i<rightBr;i++) sym[fl++]=')';
		//printf("%d %d\n",fl,si);
		printf("%s\n",sym);
	}
}
	
