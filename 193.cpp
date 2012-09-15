/*
 * Author: nzh@UESTC
 */
#include <cstdio>
#include <cstring>
using namespace std;
int rem[4]={0,1,0,2};
char res[3007],s[3007];
void bigIntegerDivide(int d){
	int si=strlen(s),i,k;
	for(i=0,k=0;i<si;i++){
		int dg=k*10+s[i]-'0';
		res[i]=dg/d+'0';
		k=dg%d;
	}
	res[si]='\0';
}
void bigIntegerMinus(int d){
	int i,k;
	int si=strlen(res);
	for(i=si-1,k=0;i>=0;i--){
		int dg=res[i]-'0'+k;
		int rm=d%10;
		if(dg<rm) k=-1;
		else k=0;
		res[i]=(dg+10-rm)%10+'0';
		d/=10;
	}
	k=0;
	while(res[k]=='0') k++;
	for(i=k;i<=si;i++){
		res[i-k]=res[i];
	}
}
int tranInt(int d){
	int n=0,i;
	int si=strlen(s);
	for(i=si-d;i<si;i++){
		n=n*10+s[i]-'0';
	}
	return n;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%s",s);
	int n;
	int si=strlen(s);
	if(si<=3){
		n=tranInt(si);
		int ans=n/2-rem[(n+1)%4];
		printf("%d\n",ans);
	}else{
		n=tranInt(2);
		int k=rem[(n+1)%4];
		bigIntegerDivide(2);
		bigIntegerMinus(k);
		printf("%s\n",res);
	}
}