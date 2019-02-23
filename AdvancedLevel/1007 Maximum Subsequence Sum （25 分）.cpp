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
int num[maxn],dp[maxn],inde[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int maxsum=0,id=0;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(i==0){
            dp[i]=num[i];
            inde[i]=num[i];
            maxsum=num[i];
            id=0;
        }
        else{
            if(dp[i-1]+num[i]>=num[i]) {
                dp[i]=dp[i-1]+num[i];
                inde[i]=inde[i-1];
            }
            else {
                dp[i]=num[i];
                inde[i]=num[i];
            }
            if(maxsum<dp[i]){
                maxsum=dp[i];
                id=i;
            }
        }
    }
    if(maxsum<0){
        printf("0 %d %d",num[0],num[n-1]);
    }
    else{
        printf("%d %d %d",maxsum,inde[id],num[id]);
    }
    return 0;
}
/*
int main()
{
    int n;
    cin>>n;
    int maxsum=-1,sum=0,x=0,y=n-1,temp=0;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
        if(sum>maxsum){
            maxsum=sum;
            y=i;
            x=temp;
        }
        if(sum<0){
            sum=0;
            temp=i+1;
        }
    }
    if(maxsum<0) maxsum=0;
    cout<<maxsum<<" "<<a[x]<<" "<<a[y]<<endl;
    return 0;
}
*/
