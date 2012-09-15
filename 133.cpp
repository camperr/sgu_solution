#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct ver{
    int c;
    int n;
    bool operator<(const ver &ot)const{
        return c<ot.c;
    }
}   a[17000],b[17000];
struct inter{
    int l,r;
}   tr[17000];
bool out[17000];
int n;
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].c,&b[i].c);
        a[i].n=b[i].n=i;
        tr[i].l=a[i].c;
        tr[i].r=b[i].c;
    }
    sort(a,a+n);
    sort(b,b+n);
    memset(out,false,sizeof(out));
    for(i=0,j=0,k=0;i<n;i++){
        if(!out[a[i].n]){
            while(j<n && b[j].n!=a[i].n) {
                //printf("%d %d %d----%d %d %d\n",i,a[i].n,a[i].c,j,b[j].n,b[j].c);
                if(tr[b[j].n].l!=a[i].c && b[j].c!=tr[a[i].n].r){
                    k++;
                    //printf("%d\n",b[j].n);
                    out[b[j].n]=true;
                }
                j++;
            }
            j++;
        }
    }
    printf("%d\n",k);
}
