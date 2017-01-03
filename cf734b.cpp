/*************************************************************************
	> File Name: cf734b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月03日 星期二 14时14分57秒
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
int main(void)
{
    ll k2,k3,k5,k6;
    cin>>k2>>k3>>k5>>k6;
    ll t=min(min(k2,k5),k6);
    k2-=t,k5-=t,k6-=t;
    ll v256=256*t;
    ll v32=0;
    if(k3&&k2){
        v32=32*min(k3,k2);
    }
    cout<<v32+v256<<endl;
    return 0;
}
