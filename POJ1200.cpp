/*************************************************************************
> File Name: POJ1200.cpp
> Author:Prgu 
> Mail:peter.wfgu@gmail.com 
> Created Time: 2017年01月07日 星期六 16时30分43秒
************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn=1000010;
const int mod=1e9+7;
vector<ll> ans;
char s[maxn];

ll mod_pow(int x,int n)
{
    ll ans=1,base=x;
    while(n){
        if(n&1)
        ans=(ans*base)%mod;
        base=(base*base)%mod;
        n>>=1;
    }
    return ans;
}

int main(void)
{
    int n,nc;
    scanf("%d%d",&n,&nc);
    scanf("%s",s);
    
    int len=strlen(s);
    ans.clear();
    ll hash=0;

    for(int i=0;i<n;i++){
        int tmp=s[i]-'a';
        hash=(hash+tmp*mod_pow(26,n-1-i)%mod)%mod;
    }

    ans.push_back(hash);

    for(int i=1;i + n - 1<len;i++){
        int tmp=s[i-1]-'a';
        hash=(hash+mod-tmp*mod_pow(26,n-1)%mod)%mod;
        hash=(hash*26)%mod;
        hash=(hash + s[i+n-1]-'a')%mod;
        ans.push_back(hash);
    }

   sort(ans.begin(),ans.end());
   int sum=unique(ans.begin(), ans.end()) - ans.begin();
    cout<<sum<<endl;

    return 0;
}

//big prime
