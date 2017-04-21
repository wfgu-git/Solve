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

double l, c, t, vr, vt1, vt2;
int n;
double dist[10005];
double dp[10005];
// c the longest length can run after charge
// t the time of charge
// double getTime(double d) {
//     double ret = 0;
//     if (d <= c) {
//         ret =  d / vt1;
//     } else {
//         ret =  c / vt1 +  (d - c) / vt2;
//     }
//     return ret;
// }

int main(int argc, char const *argv[]) {
    while (scanf("%lf", &l) != EOF) {
        scanf("%d%lf%lf", &n, &c, &t);
        scanf("%lf%lf%lf", &vr, &vt1, &vt2);
        clr(dist, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &dist[i]);
        }
        bool flag = true;
        double enemy_time = l / vr;
        for (int i = 1; i <= n + 1; i++)  dp[i] = LONG_MAX * 1.0;
        dist[0] = 0.0, dist[n + 1] = l;
        dp[0] = 0.0;
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 0; j < i; j++) {
                double length = dist[i] - dist[j];
                double time;
                if (length <= c) {
                    time = length / vt1;
                } else {
                    time = c / vt1 + (length - c) / vt2;
                }
                if (j)  time += t;
                // double cost = getTime(length);
                // cost from j to i
                // if (length > c && j != 0)  cost += t;
                dp[i] = min(dp[i], time + dp[j]);
            }
            if (dp[i] > enemy_time) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            printf("Good job,rabbit!\n");
        } else {
            printf("What a pity rabbit!\n");
        }
    }
    return 0;
}