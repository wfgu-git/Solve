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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

string s;
int k,t;
int main(void)
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>s>>k;            
        //s.erase(pos,len)        
        for(int i=0; i<(int)s.size() && k; i++){
            if(s[i] > s[i+1]){
                s.erase(i,1);
                i=-1, k--;
            }
        }
        
        while(k--){
            s = s.substr(0,s.length()-1);
        }

        while(s[0]=='0')  s = s.substr(1,s.size());
        while(s=="")  s = "0";
        cout<<s<<endl;
    }
    return 0;
}
