/*************************************************************************
	> File Name: cf734a.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月02日 星期一 11时13分25秒
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
    int n;
    while(cin>>n&&n){
        string game;
        cin>>game;
        int a=0,d=0;
        for(const char &c : game){
            if(c=='A')    a++;
            if(c=='D')    d++;
        }
        if(a==d)    cout<<"Friendship"<<endl;
        else if(a>d)    cout<<"Anton"<<endl;
        else cout<<"Danik"<<endl;
        
    }
    return 0;
}
