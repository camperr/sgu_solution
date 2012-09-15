#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double lg;
long long v,t,rem,dv;
int main(){
	int i,n;
	scanf("%lf %d",&lg,&n);
	dv=round(lg*10000);
	rem=0;
	for(i=0;i<n;i++){
		scanf("%I64d %I64d",&t,&v);
		rem=(rem+t*v)%dv;
	}
	double ans=rem;
	while(ans>=lg) ans-=lg;
	ans=(lg-ans>ans)?ans:(lg-ans);
	printf("%.4lf\n",ans);
}
