#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void)
{
    ios::sync_with_stdio(false);
    ll n,m,a;
    cin>>n>>m>>a;
    ll r,c;
    if(n%a==0)    r=n/a;
    else    r=(ll)n/a+1;
    if(m%a==0)    c=m/a;
    else    c=(ll)m/a+1;
    cout<<r*c<<endl;
    return 0;
}
