/*************************************************************************
	> File Name: cf750b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时08分26秒
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
                int len,ans=0;
                string dir;
                char d;
        for(int i=0;i<n;i++){
                        cin>>len>>dir;
                        d=dir[0];
                        if(ans==0&&d!='S')      {cout<<"NO"<<endl;return 0;}
                        if(ans==20000&&d!='N')  {cout<<"NO"<<endl;return 0;}
                        if(d=='S')    ans+=len;
                        if(d=='N')    ans-=len;
                        if(ans<0||ans>20000)    {cout<<"NO"<<endl;return 0;}
                    
        }
                if(ans==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            
    }
        return 0;

}
