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
const int maxn=10010;
struct node{
    bool havechild=false;
    int level=0;
    int father=0;
}tree[102];

int main()
{
    int n,m,a,sum;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&sum);
        if(sum!=0) tree[a].havechild=true;
        for(int j=0;j<sum;j++){
            int t;
            scanf("%d",&t);
            tree[t].father=a;
        }
    }
    int maxl=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tree[j].father==i){
                tree[j].level=tree[i].level+1;
                maxl=max(tree[j].level,maxl);
            }
        }
    }
    int res[maxl+1]={0};
    for(int i=1;i<=n;i++){
        if(!tree[i].havechild){
            res[tree[i].level]++;
        }
    }
    for(int i=0;i<=maxl;i++){
        if(i!=0) printf(" %d",res[i]);
        else printf("%d",res[i]);
    }
    return 0;
}
