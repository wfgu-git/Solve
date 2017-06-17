/*************************************************************************
	> File Name: cf118a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 17时54分17秒
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

set<char> vow={'a','e','i','o','u','y'};

int main(void)
{
    string str;
    cin>>str;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    for(int i=0;i<(int)str.length();i++){
        if(vow.count(str[i])){
            str.erase(i,1);
            i--;
        }
    }
    for(const char &c:str){
        cout<<'.'<<c;
    }
    cout<<endl;
}
