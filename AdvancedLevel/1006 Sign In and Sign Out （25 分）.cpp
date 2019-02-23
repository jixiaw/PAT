#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include <algorithm>
#include<map>
using namespace std;

struct student{
    char id[16];
    int in,out;
};

int transf(char a[]){
    int hour=(a[0]-'0')*10+(a[1]-'0');
    int minute=(a[3]-'0')*10+a[4]-'0';
    int second=(a[6]-'0')*10+a[7]-'0';
    return hour*3600+minute*60+second;
}

int main()
{
    int n;
    char in[9],out[9];
    scanf("%d",&n);
    student stu[n];
    int mi,ma;
    int temp1=0,temp2=0;
    for(int i=0;i<n;i++){
        scanf("%s %s %s",stu[i].id,in,out);
        stu[i].in=transf(in);
        stu[i].out=transf(out);
        if(i!=0){
            if(mi>stu[i].in) {mi=stu[i].in;temp1=i;}
            if(ma<stu[i].out) {ma=stu[i].out;temp2=i;}
        }
        else{
            mi=stu[i].in;
            ma=stu[i].out;
        }
    }
    printf("%s %s\n",stu[temp1].id,stu[temp2].id);

    return 0;
}

