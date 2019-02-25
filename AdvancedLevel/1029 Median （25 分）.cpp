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

int main()
{
    queue<int>a,b;
    int m,n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        a.push(t);
    }
    scanf("%d",&m);
    int mid=(m+n-1)/2;
    int cnt=0;
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        b.push(t);
        if(cnt<mid){
            if(!a.empty() && a.front()<t) a.pop();
            else b.pop();
            cnt++;
        }
    }
    for(;cnt<mid;cnt++){
        if(a.empty()) b.pop();
        else if(b.empty()) a.pop();
        else {
            if(a.front()>b.front()) b.pop();
            else a.pop();
        }
    }
    if(a.empty()) printf("%d",b.front());
    else if(b.empty()) printf("%d",a.front());
    else printf("%d",min(a.front(),b.front()));
    return 0;
}

