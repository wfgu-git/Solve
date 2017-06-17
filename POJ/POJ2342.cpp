#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 6005;
struct Edge {
	int u, v;
	int next;
} edge[maxn << 1];
int n, tot, head[maxn];
int val[maxn];
int dp[maxn][2];
void add_edge(int u, int v) {
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int solve(int u, int p, bool take) {
	if (dp[u][take] != -1)
		return dp[u][take];

	dp[u][take] = 0;
	if (take) {
		dp[u][take] = val[u];
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].v;
			if (v == p) continue;
			dp[u][1] += solve(v, u, 0);
		}
	} else {
		dp[u][take] = 0;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].v;
			if (v == p) continue;
			dp[u][0] += max(solve(v, u, 0) , solve(v, u, 1));
		}
	}
	return dp[u][take];
}
void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
	memset(dp, -1, sizeof(dp));
}

int main(int argc, char const *argv[]) {
	while (scanf("%d", &n) != EOF) {
		init();
		for (int i = 1; i <= n; i++) {scanf("%d", &val[i]);}
		int u, v;
		while (scanf("%d%d", &u, &v)) {
			if (u == 0 && v == 0) break;
			add_edge(u, v);
			add_edge(v, u);
		}
		printf("%d\n", max(solve(1, 0, 0), solve(1, 0, 1)));
	}
	return 0;
}