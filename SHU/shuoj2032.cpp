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
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

vector<int> prior;

int main(void)
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        prior.clear();
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int pri;
            cin>>pri;
            prior.push_back(pri);
        }

        int p=*(prior.begin()+m);
        vector<int>::iterator it=prior.begin();
        *(it+m)=-1;
        int sz=prior.size();
        int cnt=0;
        while(p < *max_element(prior.begin(),prior.end())&&sz>1){
            int index=max_element(prior.begin(),prior.end())-prior.begin();
            prior.erase(prior.begin()+index);
            cnt++,sz--;
            while(index--){
                int tmp=prior[0];
                prior.push_back(tmp);
                prior.erase(prior.begin());
            }
        }
        for(vector<int>::iterator it=prior.begin();it!=prior.end();it++){
            if(*it==-1) break;
            if(*it==p){
                cnt++;
            }
        }

        cout<<cnt+1<<endl;

    } 
    return 0;
}
