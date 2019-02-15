#include <iostream>
#include<stdio.h>
using namespace std;
const int maxnum=1001;
float a[maxnum]={0};
int main()
{
    int m,n,length=0;
    scanf("%d",&m);
    int a1;
    float a2;
    for(int i=0;i<m;i++){
        scanf("%d%f",&a1,&a2);
        a[a1]+=a2;
    }
    scanf("%d",&n);
    int b1;
    float b2;
    for(int i=0;i<n;i++){
        scanf("%d%f",&b1,&b2);
        a[b1]+=b2;
    }
    for(int i=0;i<maxnum;i++){
        if (a[i]!=0)length++;
    }
    printf("%d",length);
    for(int i=maxnum-1;i>=0;i--){
        if(a[i]!=0){
            printf(" %d %.1f",i,a[i]);
        }
    }

    return 0;
}
