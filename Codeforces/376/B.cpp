/*************************************************************************
	> File Name: cf731b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月05日 星期四 14时10分10秒
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
const int maxn=200005;
int a[maxn];

bool is_prime(int x)
{
    return x%2==1;
}
int main(void)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<n-1;i++){
        if(a[i]<0)   {cout<<"NO"<<endl; return 0;}
        if(is_prime(a[i])){
            a[i]--;a[i+1]--;
           // if(a[i+1]<0)    cout<<"NO"<<endl; return 0;
        }
       if(a[i]%2==0) a[i]=0;
    }
    if(a[n-1]%2!=0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
