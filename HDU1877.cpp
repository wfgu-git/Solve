/*************************************************************************
	> File Name: HDU1877.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月06日 星期五 18时10分08秒
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
int main(void)
{
    ios::sync_with_stdio(false);
    ll a,b,m;
    while(cin>>m&&m){
        cin>>a>>b;
        ll sum=a+b;
        stack<ll> s;
        if(sum==0){
            cout<<0<<endl;
            continue;
        }
        while(sum){
            s.push(sum%m);
            sum/=m;
        }
        
        while(!s.empty()){
            ll x=s.top();s.pop();
            cout<<x;
        }
        cout<<endl;

    }
    return 0;
}
