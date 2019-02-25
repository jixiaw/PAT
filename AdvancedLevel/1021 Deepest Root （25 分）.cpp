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
const int inf=0x3fffffff;
bool visit[maxn];
vector<vector<int>> edge;
int maxheight=0,temp=0;
vector<int>res;
void dfs(int now,int height){
    visit[now]=true;
    if(height>temp){
        temp=height;
    }
    for(int i=0;i<edge[now].size();i++){
        if(visit[edge[now][i]]==false) dfs(edge[now][i],height+1);
    }
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    edge.resize(n+1);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        fill(visit+1,visit+n+1,false);
        int sum=1;
        bool flag=false;
        dfs(i,1);
        for(int j=1;j<=n;j++){
            if(visit[j]==false){
                dfs(j,1);
                sum++;
                flag=true;
            }
        }
        if(flag){
            printf("Error: %d components",sum);
            return 0;
        }
        if(temp>maxheight){
            res.clear();
            res.push_back(i);
            maxheight=temp;
        }
        else if(temp==maxheight){
            res.push_back(i);
        }
        temp=0;
    }
    for(int i=0;i<res.size();i++){
        printf("%d\n",res[i]);
    }
    return 0;
}

/*
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<sstream>
#include<set>
using namespace std;
const int maxn=10010;
bool visit[maxn]={false};
bool v[maxn][maxn]={false};
vector<vector<int> > e;
int n;
set<int>res;
vector<int>temp;
int maxheight=0;
void dfs(int now,int height){
    visit[now]=true;
    if(height>maxheight){
        maxheight=height;
        temp.clear();
        temp.push_back(now);
    }
    else if(height==maxheight){
        temp.push_back(now);
    }

    for(int i=0;i<e[now].size();i++){
        if(visit[e[now][i]]==false){
            dfs(e[now][i],height+1);
        }
    }
}

int main()
{
    scanf("%d",&n);
    e.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int cnt=0;
    int now;
    for(int i=1;i<=n;i++){
        if(visit[i]==false){
            dfs(i,1);
            cnt++;
        }
        if(i==1){
            if(temp.size()>0) {
                now=temp[0];
                for(int j=0;j<temp.size();j++){
                    res.insert(temp[j]);

                }
                temp.clear();

            }
        }
    }
    if(cnt>1){
        printf("Error: %d components\n",cnt);
    }
    else{
        for(int i=1;i<=n;i++) visit[i]=false;
        dfs(now,1);
        for(int j=0;j<temp.size();j++){
            res.insert(temp[j]);
        }
        for(set<int>::iterator it=res.begin();it!=res.end();it++){
            printf("%d\n",*it);
        }
    }
    return 0;
}


*/
