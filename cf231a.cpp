/*************************************************************************
	> File Name: cf231a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 18时31分20秒
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
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        bool flag=1;
        for(int j=1;j<=3;j++){
            int x;
            cin>>x;
            if(x)    cnt++;
            if(cnt>=2&&flag){ans++;flag=0;}
        }
    }
    cout<<ans<<endl;
    return 0;
}
