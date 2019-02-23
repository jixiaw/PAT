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
bool visit[maxn];
int v[maxn][maxn];
int n;
void dfs(int root){
    visit[root]=true;
    for(int i=1;i<=n;i++){
        if(visit[i]==false&&v[root][i]==1){
            dfs(i);
        }
    }
}
int main()
{
    int m,k,x,y;S
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        v[x][y]=v[y][x]=1;
    }
    for(int j=0;j<k;j++){
        int temp;
        scanf("%d",&temp);
        fill(visit+1,visit+1+n,false);
        visit[temp]=true;
        int sum=-1;
        for(int i=1;i<=n;i++){
            if(visit[i]==false){
                sum++;
                dfs(i);
            }

        }
        printf("%d\n",sum);
    }

    return 0;
}

