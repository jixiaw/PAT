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
using namespace std;
const int maxn = 100100;

bool isprime(int n){

    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}


int main()
{
    int l,n;
    cin>>l>>n;
    string str;
    cin>>str;
    for(int i=0;i<=l-n;i++){
        string s=str.substr(i,n);
        stringstream ss;
        int temp;
        ss<<s;
        ss>>temp;
        if(isprime(temp)) {
            cout<<s;
            return 0;
        }
    }
    cout<<"404";

    return 0;
}

