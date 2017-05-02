/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
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
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a,b) scanf("%d%d",&a, &b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a, &b, &c)
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) sort(all(x)); v.erase(unique(all(v)), end())
#define mp(a,b) make_pair(a,b)
#define clr(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

int k, n, t;
struct prefix {
    int val, idx;
} p[100010];
bool cmp(prefix a, prefix b)
{
    return a.val < b.val;
}

int main(void)
{
    ios::sync_with_stdio(false);
    while(cin >> n >> k && (n + k)) {
        //memset(p,0,sizeof(p));
        p[0].val = 0, p[0].idx = 0;
        int s = 0;
        for(int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            s += temp;
            p[i].val = s;
            p[i].idx = i;
        }
        sort(p, p + 1 + n, cmp);

        for(int i = 0; i < k; i++) { // k times query
            cin >> t;
            int l, r,  sub = INF, ret = INF;
            int st, en; // record the ret [l,r]

            // move as a ruler
            l = 0, r = 1;
            while(r <= n && sub) {
                int sum = p[r].val - p[l].val; // sum ==> (l,r]
                if(abs(sum - t) < sub) {
                    sub  = abs(sum - t);
                    ret = sum;
                    st = p[l].idx;
                    en = p[r].idx;
                    //cout << st << " "  << en << endl;
                }
                if(sum < t) r++;
                else l++;
                if(l == r) r++;
            }
            cout << ret << " " << min(st, en) + 1 << " " << max(st, en) << endl;
        }
    }
    return 0;
}
