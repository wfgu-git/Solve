/*************************************************************************
	> File Name: cf752a.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时11分18秒
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
        int n,m,k;
    while(cin>>n>>m>>k){
                char pos;
                int r,d;
                if(k%2==1){  pos='L'; k++; }
                else  pos='R';
                k/=2;
        if(k%m==0){
                        r=k/m;
                        d=m;
                    
        }
        else{
                        r=k/m+1;
                        d=k%m;
                    
        }
                cout<<r<<" "<<d<<" "<<pos<<endl;
            
    }
        return 0;

}
