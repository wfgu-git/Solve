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
#include<climits>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> v;
int ans[50];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        v.clear();
        memset(ans,0,sizeof(ans));
        if(n<=4) {cout<<n<<endl;continue;}

        int p=2,tmp=n;
        while(tmp-p>=0){
            tmp-=p;
            v.push_back(p++);
        }
        
        ll res=1;
        if(!tmp){
            for(int i=0;i<(int)v.size();i++)
                res*=v[i];
        }

        else if(tmp<=(int)v.size()){
            for(int i=(int)v.size()-1;i>=0;i--){
                if(--tmp>=0) res*=(v[i]+1);
                else res*=v[i];
            }
        }

        else {
            for(int i=0;i<(int)v.size();i++){
                v[i]++;
            }
            tmp-=(int)v.size();

            for(int i=(int)v.size()-1;i>=0;i--){
                if(--tmp>=0) res*=(v[i]+1);
                else res*=v[i];
            }
        }


        cout<<res<<endl;
    }
    return 0;
}
