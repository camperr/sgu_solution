#include<cstdio>
using namespace std;
int main(){
    int a,b,ans;
    scanf("%d %d",&a,&b);
    if(b-a>=1800) ans=4;
    else if(b-a>=900) ans=3;
    else if(b-a>=300) ans=2;
    else if(b-a>=1) ans=1;
    else ans=0;
    printf("%d\n",ans);
}
