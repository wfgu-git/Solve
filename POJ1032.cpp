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
int ans[110];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        v.clear();
        memset(ans,0,sizeof(ans));
        int p=2,tmp=n;
        while(tmp-p>=0){
            tmp-=p;
            v.push_back(p++);
        }
        
        if(!tmp);

        else if(tmp<=(int)v.size()){
            for(int i=(int)v.size()-1;i>=0;i--){
                if(--tmp>=0) v[i]++;
            }
        }

        else {
            for(int i=0;i<(int)v.size();i++){
                v[i]++;
            }
            tmp-=(int)v.size();

            for(int i=(int)v.size()-1;i>=0;i--){
                if(--tmp>=0) v[i]++;
            }
        }

        for(int i=0;i<(int)v.size();i++){
            if(i) cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}
