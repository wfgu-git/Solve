#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
map<int, int> cnt[maxn];
map<int, ll> sum[maxn];
int col[maxn];
ll ret[maxn];
vector<vector<int> > g;
int n;
void dfs(int u, int p)
{
    cnt[u][col[u]] = 1;
    sum[u][1] = (ll)col[u];

    for(auto v : g[u]) {
        if(v != p) {
            dfs(v, u);
            if(cnt[u].size() < cnt[v].size()) {
                swap(cnt[u], cnt[v]);
                swap(sum[u], sum[v]);
            }
            for(auto kv : cnt[v]) {
                cnt[u][kv.first] += kv.second;
                int t = cnt[u][kv.first];
                sum[u][t] += (ll)kv.first;
            }
            cnt[v].clear();
            sum[v].clear();
        }
    }
    ret[u] = sum[u].rbegin()->second;
}
void init()
{
    g.resize(n + 2);
    g.clear();
}
int main()
{
    scanf("%d", &n);
    init();
    for_each(col + 1, col + 1 + n, [](int &x) {scanf("%d", &x);});
    for(int i = 0, u, v; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for_each(ret + 1, ret + 1 + n, [](ll x) {printf("%I64d ", x);});
    return 0;
}

