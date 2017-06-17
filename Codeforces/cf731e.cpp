/*************************************************************************
	> File Name: cf731e.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 20时24分02秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
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
ll n,ans;
ll a[200005];
ll dp[200005];

//只与第一次拿的位置相关

int main(void)
{
    cin>>n;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    ans=a[n];
    for(int i=n-1;i>=2;i--){
        ans=max(ans,a[i]-a[n]);
    }
    cout<<ans<<endl;
    return 0;
}
