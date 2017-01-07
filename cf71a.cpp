/*************************************************************************
	> File Name: cf71a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 17时42分00秒
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
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        int len=str.length();
        if(len<=10){
            cout<<str<<endl;
            continue;
        }
        else{
            cout<<str[0]<<len-2<<str[len-1]<<endl;
        }
    }
    return 0;
}
