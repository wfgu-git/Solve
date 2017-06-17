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
typedef long long ll;
// typedef __int64 ll;
typedef pair<int, int> PII;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

const int maxn = 20000;
struct Edge {
	int u, v;
} e[20200];
int first[maxn], Next[maxn];
bool is_cut[maxn];
int dfn[maxn], low[maxn];
int dfs_clock, cut_point, eNum;

void tarjan(int u, int pre)
{
	int child = 0;
	dfn[u] = low[u] = ++dfs_clock;
	for(int i = first[u]; i != -1; i = Next[i]) {
		int v = e[i].v;
		child++;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(u == 1 && child >= 2 || u != 1 && low[v] >= dfn[u]) {
				is_cut[u]++;
			}
		} else if(pre != v) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void add_edge(int u, int v)
{
	e[eNum].u = u, e[eNum].v = v;
	Next[eNum] = first[e[eNum].u];
	first[e[eNum].u] = eNum++;
}

void init()
{
	dfs_clock = cut_point = eNum = 0;
	mset(first, -1);
	mset(dfn, 0);
	mset(low, 0);
	mset(is_cut, 0);
	mset(e, 0);
}

int main(int argc, char const * argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, u, v;
	while(scanf("%d", &n) != EOF && n) {
		init();
		while(scanf("%d", &u) != EOF && u) {
			while(getchar() != '\n') {
				scanf("%d", &v);
				add_edge(u, v);
				add_edge(v, u);
			}
		}

		tarjan(1, -1);
		for(int i = 1; i <= n; i++) {
			if(is_cut[i])
				cut_point++;
		}
		printf("%d\n", cut_point);
	}
	return 0;
}
