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

const int maxn = 105;
int m, n;
char grid[maxn][maxn];
// bool vis[maxn][maxn];
int dr[] = { -1, 1, 0, 0, -1, 1, -1, 1};
int dc[] = {0, 0, -1, 1, -1, -1, 1, 1};
bool inside(int r, int c) {
    if(r < 0 || r >= m || c < 0 || c >= n) return false;
    return true;
}

void Dfs(int r, int c) {
    if(inside(r, c) == false) return;
    if(grid[r][c] == '*') return;
    grid[r][c] = '*';
    for(int i = 0; i < 8; i++) {
        Dfs(r + dr[i], c + dc[i]);
    }
}
int main(int argc, char const *argv[]) {
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
    while(~iscanf2(m, n) && (m + n)) {
        clr(grid, 0);
        // clr(vis, 0);
        for(int i = 0; i < m; i++) {
            scanf("%s", &grid[i]);
        }

        //dfs
        int ret = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == '@') {
                    ret++;
                    Dfs(r, c);
                }
            }
        }

        printf("%d\n", ret);
    }
    return 0;
}


