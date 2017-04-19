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

const int maxn = 10000;
int N, tot;
int w[maxn], Head[maxn];
int dp[maxn][2];
// 0 -- > not come
// 1 -- > come
// dp[i][0] = max{dp[j][0], dp[j][1]}
// dp[i][1] = max{dp[j][0]}
struct Edge {
	int from, to;
	int next;
} edge[maxn];
void add_edge(int u, int v) {
	edge[tot].from = u, edge[tot].to = v;
	edge[tot].next = Head[u];
	Head[u] = tot++;
	edge[tot].from = v, edge[tot].to = u;
	edge[tot].next = Head[v];
	Head[v] = tot++;
}


int Dfs(int u, int pre, bool is_come) {
	if(dp[u][is_come] != -1) {
		return dp[u][is_come];
	}
	dp[u][is_come] = 0;
	if(is_come) {
		dp[u][is_come] += w[u];
		for(int i = Head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if(v != pre) {
				dp[u][is_come] += Dfs(v, u, 0);
			}
		}
	} else {
		for(int i = Head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if(v != pre) {
				dp[u][is_come] += Max(Dfs(v, u, 0), Dfs(v, u, 1));
			}
		}
	}
	return dp[u][is_come];
}

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	while(~iscanf(N)) {
		clr(w, 0), clr(edge, 0), clr(Head, -1), clr(dp, -1);
		for(int i = 1; i <= N; i++) {
			iscanf(w[i]);
		}

		tot = 0;
		int u, v;
		while(iscanf2(u, v) && (u + v)) {
			add_edge(u, v);
		}

		int ret = Max(Dfs(1, 1, 0), Dfs(1, 0, 0));
		printf("%d\n", ret);
	}
	return 0;
}

