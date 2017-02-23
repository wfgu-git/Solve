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
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pr(a) printf("%d\n",a)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 50010;
map<int, vector<int> > ls;
int a[maxn], pos[maxn];
ll res[maxn];
ll bit[maxn];
int block_size, n, m, id;
struct Interval {
    int l, r;
    int id;
} qry[maxn];
bool cmp2(Interval a, Interval b)
{
    if (pos[a.l] == pos[b.l]) {
        return a.r < b.r;
    } else {
        return pos[a.l] < pos[b.l];
    }
}

// struct Node {
//     int v;
//     int order;
// } ls[maxn];
// bool cmp1(Node a, Node b)
// {
//     return a.v < b.v;
// }

int lowbit(int x)
{
    return x & -x;
}

ll getsum(int x)
{
    ll res = 0;
    while (x > 0) {
        res += bit[x];
        x -= lowbit(x);
    }
    return res;
}

void update(int x, int k)
{
    while (x <= n) {
        bit[x] += k;
        x += lowbit(x);
    }
}

int main(void)
{
    sc(n);
    block_size = ceil(sqrt(1.0 * n));
    for (int i = 1; i <= n; i++) {
        // sc(ls[i].v);
        // ls[i].order = i;
        int temp;
        sc(temp);
        ls[temp].push_back(i);
        pos[i] = (i - 1) / block_size;
    }
    sc(m);
    // sort(ls + 1, ls + n + 1, cmp1);
    // for (int i = 1; i <= n; i++) {
    //     a[ls[i].order] = i;
    // }

    int p = 1;
    for (auto &kv : ls) {
        for (int i = 0; i < (int)kv.se.size(); i++) {
            a[kv.se[i]] = p;
        }
        p++;
    }
    for (int i = 0; i < m; i++) {
        sc2(qry[i].l, qry[i].r);
        qry[i].id = i;
    }
    sort(qry, qry + m, cmp2);

    int l, r;
    ll ans;
    l = 1;
    r = 0;
    ans = 0;
    for (int i = 0; i < m; i++) {
        id = qry[i].id;

        while (r < qry[i].r) {
            update(a[++r], 1);
            ans += r - l + 1 - getsum(a[r]);
        }
        while (r > qry[i].r) {
            ans -= r - l + 1 - getsum(a[r]);
            update(a[r--], -1);
        }
        while (l < qry[i].l) {
            ans -= getsum(a[l] - 1);
            update(a[l++], -1);
        }
        while (l > qry[i].l) {
            update(a[--l], 1);
            ans += getsum(a[l] - 1);
        }
        res[id] = ans;
    }

    for (int i = 0; i < m; i++) {
        printf("%lld\n", res[i]);
    }
    return 0;
}
