#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<sstream>
#include<set>
#include<unordered_map>
using namespace std;
const int maxn=1010;
const int inf=0x3fffffff;
bool visit[maxn];
int v[maxn][maxn]={0},bike[maxn],d[maxn];
int n,cmid;
vector<vector<int> > pre;
vector<int>res,temp;
int resneed=-1,resremain=-1;
void dijkstra(int root){
    fill(visit,visit+n+1,false);
    fill(d,d+n+1,inf);
    d[root]=0;
    for(int i=0;i<=n;i++){
        int u=-1,MIN=inf;
        for(int j=0;j<=n;j++){
            if(visit[j]==false&&d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1) return;
        visit[u]=true;
      //  printf("%d ",u);
        for(int j=0;j<=n;j++){
            if(visit[j]==false&&v[u][j]!=0){
                if(d[j]>d[u]+v[u][j]){
                    d[j]=d[u]+v[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if(d[j]==d[u]+v[u][j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}
void dfs(int now){
    temp.push_back(now);
    if(now==0){
        int need=0,remain=0;
        for(int i=temp.size()-2;i>=0;i--){
            if(bike[temp[i]]>=cmid){
                remain+=bike[temp[i]]-cmid;
            }
            else{
                int offset=cmid-bike[temp[i]];
                if(remain>=offset){
                    remain-=offset;
                }
                else{
                    need+=offset-remain;
                    remain=0;
                }
            }
        }
        if(resneed==-1){
            res=temp;
            resneed=need;
            resremain=remain;
        }
        else if(resneed>need){
            res=temp;
            resneed=need;
            resremain=remain;
        }
        else if(resneed==need){
            if(resremain>remain){
                res=temp;
            resremain=remain;
            }
        }
        temp.pop_back();
        return;

    }
    for(int i=0;i<pre[now].size();i++){

        dfs(pre[now][i]);

    }
    temp.pop_back();
}



int main()
{
    int cmax,sp,m;
    scanf("%d %d %d %d",&cmax,&n,&sp,&m);
    pre.resize(n+1);
    cmid=cmax/2;
    for(int i=1;i<=n;i++){
        scanf("%d",&bike[i]);
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        v[a][b]=v[b][a]=c;
    }
    dijkstra(0);
    dfs(sp);
    printf("%d 0",resneed);
    for(int i=res.size()-2;i>=0;i--){
        printf("->%d",res[i]);
    }
    printf(" %d",resremain);

    return 0;
}

