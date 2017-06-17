/*************************************************************************
	> File Name: cf742b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月03日 星期二 01时30分59秒
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

/*
const int maxn=100005;
int a[maxn];
int cmp[maxn];
int main(void)
{
    ios::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n;i++)    cmp[i]=a[i]^x;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cmp[j]==a[i])
                cnt++;
        }
    }

    cout<<cnt/2<<endl;
    return 0;

}
*/   //TLE
ll a[200010];
ll n,x,cnt,tmp;
int main(void)
{
    ios::sync_with_stdio(false);
    cin>>n>>x;
    for(ll i=0;i<n;i++){
        cin>>tmp;
        cnt+=a[tmp^x];
        a[tmp]++;
    }
    cout<<cnt<<endl;
    return 0;
}

