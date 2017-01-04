/*************************************************************************
	> File Name: cf746a.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时13分52秒
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
        int a,b,c;
        while(cin>>a>>b>>c)
    {
                int aa=a,bb=b/2,cc=c/4;
                int num=min(min(aa,bb),cc);
                cout<<num*7<<endl;
            
    }
        return 0;

}
