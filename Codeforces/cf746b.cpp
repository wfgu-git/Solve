/*************************************************************************
	> File Name: cf746b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时14分20秒
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
        while(cin>>n&&n)
    {
                string str,ans="";
                cin>>str;
                while(n)
        {
                        if((n%2))
            {
                                ans=ans+str[0];
                                str=str.substr(1,str.length()-1);
                                n--;
                            
            }
                        else
            {
                                ans=str[0]+ans;
                                str=str.substr(1,str.length()-1);
                                n--;
                            
            }
                    
        }
                cout<<ans<<endl;
            
    }
        return 0;

}
