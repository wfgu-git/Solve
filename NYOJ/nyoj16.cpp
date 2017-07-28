/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
// typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a, b) scanf("%d%d", &a, &b)
#define iscanf3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define mo(a, b) (((a) % (b) + (b)) % (b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) \
    sort(all(x)); \
    v.erase(unique(all(v)), end())
#define mp(a, b) make_pair(a, b)
#define clr(x, i) memset(x, i, sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l, m, rt << 1
#define rch m + 1, r, rt << 1 | 1
#define rep(i, x, n) for (int i = x; i < n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 1010;
struct rec {
    int x, y;
    rec() {}
    rec(int _x, int _y) : x(Min(_x, _y)), y(Max(_x, _y)) {}
} rectangle[maxn];
bool cmp(rec a, rec b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool canInside(rec a, rec b) {
    if ((a.x < b.x && a.y < b.y) || (a.y < b.x && a.x < b.y)) return true;
    return false;
}
int dp[maxn];
int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        clr(rectangle, 0);
        int n;
        scanf("%d", &n);
        int x, y;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            rectangle[i] = rec(x, y);
        }
        sort(rectangle, rectangle + n, cmp);
        clr(dp, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (canInside(rectangle[j], rectangle[i]) &&
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int ret = dp[0];
        for (int i = 0; i < n; i++) {
            if (ret < dp[i]) ret = dp[i];
        }
        printf("%d\n", ret + 1);
    }
    return 0;
}
