#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 3005;
const int inf = 0x3f3f3f3f;
struct Edge {
    int u, v, d;
    int next;
} edge[maxn << 1];
int tot, head[maxn];
int n, m;
int num[maxn], temp[maxn];
int dp[maxn][maxn];
void add_edge(int u, int v, int d) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].d = d;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}
void dfs(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        int d = edge[i].d;
        dfs(v);
        for (int j = 0; j <= num[u]; j++) {
            temp[j] = dp[u][j];
        }
        for (int j = 0; j <= num[u]; j++) {
            for (int k = 1; k <= num[v]; k++) {
                dp[u][j + k] = max(dp[u][j + k], temp[j] + dp[v][k] - d);
            }
        }
        num[u] += num[v];
    }
}
int main(int argc, char const *argv[]) {
    while (scanf("%d%d", &n, &m) == 2) {
        init();
        for (int i = 1; i <= n - m; i++) {
            num[i] = 0;
            int k, v, d;
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d%d", &v, &d);
                add_edge(i, v, d);
            }
        }
        // memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = -inf;
            }
        }
        for (int i = n - m + 1; i <= n; i++) {
            num[i] = 1;
            scanf("%d", &dp[i][1]);
        }
        dfs(1);
        for (int i = m; i >= 0; i--) {
            if (dp[1][i] >= 0) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}