/*  gyt
       Live up to every day            */
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#include <time.h>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 510000+10;
const ll maxm = 1e7;
const int modd = 10000007;
const int INF = 1<<30;
const db eps = 1e-9;
int pos[maxn], pre[maxn], nex[maxn];

void solve() {
    int n, k;  scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++) {
        int x;  scanf("%d", &x);
        pos[x]=i;  pre[i]=i-1,  nex[i]=i+1;
    }
    pre[0]=0;  nex[n+1]=n+1;
    ll sum=0;
    for (int j=1; j<=n; j++) {
        int x=pos[j];
        int rq[110];
        int lc=0, rc=0;
       // cout<<"x:"<<x<<endl;
        for (int i=x; i<=n&&rc<k; i=nex[i]) {
            rq[++rc]=nex[i]-i;
           // cout<<nex[i]<<" "<<i<<endl;
        }
        ll ans=0;
        for (int i=x; i>0&&lc<k; i=pre[i]) {
            lc++;
            int r=k-lc+1;
            if (r>rc)  continue;
            ans+=(i-pre[i])*rq[r];　　//前面有多少个比他小的数，我们就可以构成那么多的区间
            //cout<<"ans:"<<ans<<endl;
            //cout<<(i-pre[i])<<" "<<rq[r]<<endl;
        }
        //cout<<"rc:"<<rc<<" lc:"<<lc<<endl;
        sum+=ans*j;
        pre[nex[x]]=pre[x];
        nex[pre[x]]=nex[x];
        //cout<<j<<" "<<ans<<endl;
        //cout<<"---------------"<<endl;
    }
    cout<<sum<<endl;
}
int main() {
    int t = 1;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    //getchar();
    while(t--)
        solve();
    return 0;
}
