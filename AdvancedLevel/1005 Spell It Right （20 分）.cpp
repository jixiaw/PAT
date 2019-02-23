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
string a[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
    string str;
    cin>>str;
    int sum=0;
    for(int i=0;i<str.size();i++){
        sum+=str[i]-'0';
    }
    if(sum>99){
        cout<<a[sum/100]<<" "<<a[sum%100/10]<<" "<<a[sum%10];
    }
    else if(sum<10) cout<<a[sum];
    else cout<<a[sum/10]<<" "<<a[sum%10];
    return 0;
}
