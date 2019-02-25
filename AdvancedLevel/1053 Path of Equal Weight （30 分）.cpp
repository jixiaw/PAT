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
const int maxn=105;
const int inf=0x3fffffff;
bool visit[maxn];
int dp[maxn][maxn],w[maxn];
struct Node{
    int val;
    vector<int>child;
}node[maxn];
vector<int>temp;
int s;
void dfs(int now,int w){
    //visit[now]=true;

    w=w+node[now].val;
    if(w>s) return;
    temp.push_back(node[now].val);
    if(w==s){
        if(node[now].child.empty()){
            for(int i=0;i<temp.size();i++){
                if(i==temp.size()-1) printf("%d\n",temp[i]);
                else printf("%d ",temp[i]);
            }
        }
        temp.pop_back();
        return;
    }
    for(int i=node[now].child.size()-1;i>=0;i--){
        dfs(node[now].child[i],w);
    }
    temp.pop_back();
}

bool cmp(int a,int b){
    return node[a].val<node[b].val;
}

int main()
{
    int n,m;
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&node[i].val);
    }
    int a,sum,t;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&sum);
        for(int j=0;j<sum;j++){
            scanf("%d",&t);
            node[a].child.push_back(t);
        }
        sort(node[a].child.begin(),node[a].child.end(),cmp);
    }
    dfs(0,0);
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
const int maxn=105;
int n;
int value[maxn];

struct node{
    int val=0;
    int father=-1;
    int flag=0;//спнч╨╒вс
    int sum=0;
}tree[maxn];
vector<vector<int> > res;

bool cmp(vector<int>a,vector<int>b){
    for(int i=0;i<a.size()&&i<b.size();i++){
        if(a[i]!=b[i]) return a[i]>b[i];
    }
    return a.size()>b.size();
}

int main()
{
    int m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&value[i]);
        tree[i].val=value[i];
        tree[i].sum=value[i];
    }
    for(int i=0;i<m;i++){
        int tmp,c;
        scanf("%d %d",&tmp,&c);
        tree[tmp].flag=1;
        for(int j=0;j<c;j++){
            int t;
            scanf("%d",&t);
            tree[t].father=tmp;
        }
    }
    for(int i=0;i<n;i++){

        if(i!=0) tree[i].sum+=tree[tree[i].father].sum;
        if(tree[i].flag==0&&tree[i].sum==s){
            vector<int>temp;
            int cur=i;
            while(1){
                temp.insert(temp.begin(),tree[cur].val);
                if(tree[cur].father==-1) break;
                cur=tree[cur].father;
            }
            res.push_back(temp);
        }
    }
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            if(j==0) printf("%d",res[i][j]);
            else printf(" %d",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}

*/
