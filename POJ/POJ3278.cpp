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
#define lch l,m,rt<< 1
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

int dm[] = { -1, 1,  2};
int Move(int x, int tag) {
    int ret = 0;
    if(tag == 1) {
        ret = x + 1;
    } else if(tag == -1) {
        ret = x - 1;
    } else {
        ret = x * 2;
    }
    return ret;
}

const int maxn = 100010;
int step[maxn];
int ret;
void Bfs(int start, int target) {
    if(start == target) {
        ret = 0;
        return;
    }
    clr(step, -1);
    step[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < 3; i++) {
            int nx = Move(cur, dm[i]);
            if(nx < 0 || nx > 100000)  continue;
            if(step[nx] == -1) {
                step[nx] = step[cur] + 1;
                if(nx == target) {
                    ret = step[nx];
                    return;
                }
                q.push(nx);
            }
        }
    }
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        Bfs(n, k);
        printf("%d\n", ret);
    }
    return 0;
}
