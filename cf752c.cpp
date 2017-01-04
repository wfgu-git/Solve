/*************************************************************************
	> File Name: cf752c.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时12分35秒
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
    while(cin>>n){
                string dir;
                int cnt=1;
                char r=0,c=0;
                cin>>dir;
        for(int i=0;i<n;i++){
            if(dir[i]=='L'||dir[i]=='R'){
                                if(!r)    r=dir[i]; 
                else if(r!=dir[i]){
                                        cnt++;
                                        r=dir[i];
                                        c=0;
                                    
                }
                            
            }
            if(dir[i]=='U'||dir[i]=='D'){
                                if(!c)    c=dir[i];
                else if(c!=dir[i]){
                                        cnt++;
                                        c=dir[i];
                                        r=0;
                                    
                }
                            
            }
                    
        }
                cout<<cnt<<endl;
            
    }
        return 0;

}
