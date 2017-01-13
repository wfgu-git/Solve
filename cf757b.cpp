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

const int maxn=100005;
int cnt[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    int ans=1;
    for(int i=2;i<maxn;i++){
        int cur=0;
        for(int j=i;j<maxn;j+=i){
            cur+=cnt[j];
        }
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
    return 0;
}
