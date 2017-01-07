/*************************************************************************
	> File Name: cf96a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 18时12分40秒
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
char str[105];
int main(void)
{
    scanf("%s",str);
    if(strstr(str,"0000000")||strstr(str,"1111111"))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
}
