//1303151	23.05.12 13:22	if	 231	.CPP	Accepted	31 ms	3047 kb
#include<cstdio>
using namespace std;
int pri[1007];
bool isNotPrime[1000007]={0};
int ans[10007];
void findPrime(int n){
    int i,j,k;
    for(i=2,k=0;i<1000;i++){
        bool yes=true;
            for(j=0;j<k && pri[j]*pri[j]<=i;j++){
                if(i%pri[j]==0){
                    yes=false;
                    break;
                }
            }
            if(yes) pri[k++]=i;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<k && pri[j]*i<=n;j++){
            isNotPrime[pri[j]*i]=true;
            if(i%pri[j]==0) break;
        }
    }
}
int main(){
    int n,i,j;
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    findPrime(n);
    for(i=4,j=0;i<=n;i++){
        if(!isNotPrime[i] && !isNotPrime[i-2]){
            ans[j++]=i-2;
        }
    }
    printf("%d\n",j);
    for(i=0;i<j;i++){
        printf("2 %d\n",ans[i]);
    }
}
