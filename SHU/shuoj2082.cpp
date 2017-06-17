#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define ptlld(a) printf("%lld\n",a)
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 1010;
int cnt[maxn];
int main(int argc, char const *argv[]) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);

    int T, n, k;
    scanf("%d", &T);
    while(T--) {
        mset(cnt, 0);
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            ++cnt[x % k];
        }

        int i, j;
        bool flag = false;
        for(i = 0; i < k; i++) {
            if(cnt[i]-- > 0) {
                for(j = 0; j < k; j++) {
                    if(cnt[j]-- > 0) {
                        if(cnt[(k - i - j + k) % k] > 0) {
                            flag = true;
                            break;
                        }
                    }
                    ++cnt[j];
                }
            }
            ++cnt[i];
        }
        
        if(flag)  printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}
