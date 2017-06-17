/*************************************************************************
	> File Name: cf733a.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月02日 星期一 11时34分23秒
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
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int ans=-1,alph=1;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='U'||s[i]=='I'||s[i]=='Y') {ans=max(ans,alph); alph=1;}
        else    alph++;
    }
    ans=max(ans,alph);
    cout<<ans<<endl;
    return 0;
}
