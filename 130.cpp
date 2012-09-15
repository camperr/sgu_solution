//1303047	23.05.12 05:26	if	 130	.CPP	Accepted	15 ms	887 kb
#include<cstdio>
long long a[37];
using namespace std;
int main(){
    int k,i,j;
    scanf("%d",&k);
    a[0]=1,a[1]=1;
    for(i=2;i<=k;i++) {
        a[i]=0;
        for(j=0;j<i;j++){
            a[i]+=a[j]*a[i-1-j];
        }
        //printf("%d %lld\n",i,a[i]);
    }
    printf("%I64d %d\n",a[k],k+1);
}
