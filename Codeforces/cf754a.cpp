/*************************************************************************
	> File Name: cf754a.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 09时45分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=105;
int a[maxn];


int main(void)
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    a[0]=0;
    int sum=0,cnt0=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)
        cnt0++;
        sum+=a[i];
        
    }
    if(cnt0==n)   {cout<<"NO"<<endl; return 0;}
    if(sum!=0)    {cout<<"YES\n"<<1<<'\n'<<1<<" "<<n<<endl; return 0;}
    else{
        cout<<"YES"<<endl<<"2\n";
        int p;
        for(p=0;p<=n;p++){
            if(a[p]!=0)
                break;
        }
        cout<<1<<" "<<p<<endl;
        cout<<p+1<<" "<<n<<endl;
    }
    return 0;
}
