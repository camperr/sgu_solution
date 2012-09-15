#include<cstdio>
#include<cstring>
using namespace std;
int vis[1007]={-1};
int no[1007];
int main(){
    int i,j,k,a,b,c,m,f;
    freopen("in.txt","r",stdin);
    scanf("%d %d %d %d %d %d",&f,&a,&b,&c,&m,&k);
    i=f%m,j=0;
    //printf("%d------------",i);
    memset(vis,-1,sizeof(vis));
    while(vis[i]==-1){
         // printf("------------");
        //printf("a[%d]=%d\n",j,i);
        vis[i]=j;
        no[j]=i;
        j++;
        i=(a*i*i+b*i+c)%m;
    }
    int q=j-vis[i];
    if(k==0) printf("%d\n",f);
    else if(k<vis[i]) printf("%d\n",no[k]);
    else printf("%d\n",no[vis[i]+(k-vis[i])%q]);
}
