/*************************************************************************
	> File Name: cf731a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 23时07分03秒
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
int x[105];
int main(void)
{
    string s;
    cin>>s;
    s='a'+s;
    int len=s.size();
    for(int i=0;i<len;i++) {x[i]=s[i];}
    int ans=0;
    for(int i=1;i<len;i++){
        int a=min(x[i-1],x[i]);
        int b=max(x[i-1],x[i]);
        ans+=min((b-a),(a-b+26)%26);
        continue;
    }
    cout<<ans<<endl;
    return 0;
}
