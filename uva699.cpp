#include<bits/stdc++.h>
using namespace std;

const int maxn=1000+5;
int sum[maxn];

void build(int p)
{
    int v;cin>>v;
    if(v==-1)   return;
    sum[p]+=v;
    build(p-1);
    build(p+1);
}

bool input()
{
    int v;cin>>v;
    if(v==-1)   return false;
    memset(sum,0,sizeof(sum));
    int pos=maxn/2;
    sum[pos]=v;
    build(pos-1);
    build(pos+1);
}

int main(void)
{
    int kase=0;
    while(input())
    {
        int p=0;
        while(sum[p]==0)    p++;
        cout<<"Case "<<++kase<<":\n"<<sum[p++];
        while(sum[p]!=0)   cout<<" "<<sum[p++];
        cout<<"\n\n";
    }
    return 0;
}
