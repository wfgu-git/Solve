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

//gcd lcm
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

struct Interval {
    int l, r;
    int d;  // the length of this []
    Interval() {}
    Interval(int _l, int _r): l(_l), r(_r), d(r - l + 1) {}
};
bool cmp(Interval p, Interval q) {
    return p.l < q.l;
}
int cntDays(Interval p, Interval q) {
    int ret = Min(p.r, q.r) - Max(p.l, q.l) + 1;
    return ret;
}
Interval a[110];
Interval b[110];

int main(int argc, char const *argv[]) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        clr(a, 0), clr(b, 0);
        //input
        int n, m, x, y;
        scanf("%d%d%d%d", &n, &m, &x, &y);
        int l, r, cntX, cntY;
        cntX = 0;
        for(int i = 0; i < x; i++) {
            scanf("%d%d", &l, &r);
            if(r - l + 1 < m)  continue;
            a[cntX++] = Interval(l, r);
        }
        sort(a, a + cntX, cmp);
        cntY = 0;
        for(int i = 0; i < y; i++) {
            scanf("%d%d", &l, &r);
            if(r - l + 1 < m)  continue;
            b[cntY++] = Interval(l, r);
        }
        sort(b, b + cntY , cmp);

        int ret = 0;
        for(int i = 0; i < cntX; i++) {
            for(int j = 0; j < cntY; j++) {
                // if(a[i].r <= b[i].l)  continue;
                int temp;
                if((temp = cntDays(a[i], b[j])) >= m) {
                    ret += temp - m + 1;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}


