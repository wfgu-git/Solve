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

int k;
// 1/k = 1/x + 1/y
// x >= y
// 1/x <= 1/y
// y <= 2*k
bool isInt(double x) {
    if (x - (int)x == 0)  return true;
    return false;
}

vector<PII> ret;
int main(int argc, char const *argv[]) {
    while (~iscanf(k)) {
        ret.clear();
        int x, y;
        int cnt = 0;
        for (y = k + 1; y <= 2 * k; y++) {
            double xx = 1.0 * k * y / (1.0 * (y - k));
            // printf("%d  %f\n", y, xx);
            if (isInt(xx) == true) {
                cnt++;
                x = (int)xx;
                ret.push_back(make_pair(x, y));
            }
        }
        printf("%d\n", ret.size());
        for (const pair<int, int> &p : ret) {
            printf("1/%d = 1/%d + 1/%d\n", k, p.fi, p.se);
        }
    }
    return 0;
}