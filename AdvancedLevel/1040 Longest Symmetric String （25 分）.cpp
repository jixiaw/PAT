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
int dp[maxn][maxn];
int main()
{
    string str;
    getline(cin,str);
    int maxl=1;
    for(int i=0;i<str.size();i++){
        dp[i][i]=1;
        if(i!=str.size()-1){
            if(str[i]==str[i+1]){
                dp[i][i+1]=1;
                maxl=2;
            }

        }
    }
    for(int s=3;s<=str.size();s++){
        for(int i=0;i<=str.size()-s;i++){
            int j=i+s-1;
            if(dp[i+1][j-1]==0) dp[i][j]=0;
            else{
                if(str[i]==str[j]) {dp[i][j]=1;maxl=s;}
                else dp[i][j]=0;
            }
        }
    }
    printf("%d",maxl);
    return 0;
}

