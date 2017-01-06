/*************************************************************************
	> File Name: cf1a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月06日 星期五 21时34分38秒
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
