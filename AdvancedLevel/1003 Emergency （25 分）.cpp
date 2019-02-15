#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include <algorithm>
#include<vector>
using namespace std;
const int MaxSize=505;
int n,c1,c2;
int L[MaxSize][MaxSize]={0};
int numTeam[MaxSize];
bool visit[MaxSize]={false};
int sum=0,minlen=-1,maxtem=0;
void dfs(int index,int length,int sumtem){
    if(minlen>0&&length>minlen) return;
    if(index==c2){
        if(minlen<0||length<minlen){
            minlen=length;
            maxtem=sumtem;
            sum=1;
        }
        else if(length==minlen){
            sum++;
            if(sumtem+numTeam[c2]>maxtem)
                maxtem=sumtem;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(visit[i]==false&&L[index][i]!=0) {
            visit[i]=true;
            dfs(i,length+L[index][i],sumtem+numTeam[i]);
            visit[i]=false;
        }
    }
}

int main()
{
    int m;
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++){
        scanf("%d",&numTeam[i]);
    }
    int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&v);
        L[x][y]=v;
        L[y][x]=v;
    }
    visit[c1]=true;
    dfs(c1,0,numTeam[c1]);
    printf("%d %d\n",sum,maxtem);
    return 0;
}

