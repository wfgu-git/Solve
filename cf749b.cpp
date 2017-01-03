/*************************************************************************
	> File Name: cf749b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月03日 星期二 15时04分20秒
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
int x[3];
int y[3];
int ansx[3];
int ansy[3];
int main(void)
{
    ios::sync_with_stdio(false);
    cout<<3<<endl;
    for(int i=0;i<3;i++){
        cin>>x[i]>>y[i];
    }
    
    for(int i=0;i<3;i++){
        ansx[i]=x[(i+1)%3]+x[(i+2)%3]-x[i];
        ansy[i]=y[(i+1)%3]+y[(i+2)%3]-y[i];
    }

    for(int i=0;i<3;i++){
        cout<<ansx[i]<<" "<<ansy[i]<<endl;
    }
    return 0;
}
