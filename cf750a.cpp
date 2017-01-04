/*************************************************************************
	> File Name: cf750a.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时09分08秒
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
        int n,k;
    while(cin>>n>>k){
                int t=5,leave=4*60,cnt=0;
                leave=leave-k;
        while(leave-t>=0&&n){
                        cnt++;
                        n--;
                        leave-=t;
                        t+=5;
                    
        }
                cout<<cnt<<endl;
            
    }
        return 0;

}
