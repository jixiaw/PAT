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


int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int c=a+b;
    if(c==0) {
        printf("0");
        return 0;
    }
    if(c<0) {printf("-");c=-c;}
    int x=c/1000000;
    int y=c%1000000/1000;
    int z=c%1000;
    if(x!=0){
        printf("%d,%03d,%03d",x,y,z);
    }
    else{
        if(y!=0){
            printf("%d,%03d",y,z);
        }
        else printf("%d",z);
    }

    return 0;
}
