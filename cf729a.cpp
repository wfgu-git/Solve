/*************************************************************************
    > File Name: cf729a.cpp
    > Author:Pr 
    > Mail:peter.wfgu@gmail.com 
    > Created Time: 2017年01月03日 星期二 20时20分29秒
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
#include<regex>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    int n;
    string s;
    cin>>n>>s;
    regex reg("o(go)+");
    string rep("***");
    string ans=regex_replace(s,reg,rep);
    cout<<ans<<endl;

    return 0;
}

