#include <bits/stdc++.h>
using namespace std;
#define lch l,m,rt<<1
#define rch m,r,rt<<1|1
typedef long long ll;
const int maxn = 1e6;
int col[maxn];
vector< vector<int> > g;
int nn;
struct segtree{ ll lazy, col; }seg[maxn << 2];
int st[maxn], ft[maxn], dfs_clock;
void init(int n)
{
    nn = n;
    g.resize(n + 2);
    g.clear();
    dfs_clock = 0;
}
void getinfo(int u, int p)
{
    st[u] = ++dfs_clock;
    for(auto v : g[u]){
        if(v != p)
            getinfo(v, u);
    }
    ft[u] = dfs_clock + 1;
}
void push_up(int rt)
{
    seg[rt].col = seg[rt << 1].col | seg[rt << 1 | 1].col;
}
void push_down(int rt)
{
    if(!seg[rt].lazy)
        return;
    seg[rt << 1].lazy = seg[rt << 1 | 1].lazy = seg[rt].lazy;
    seg[rt <<1].col = seg[rt << 1 | 1].col = seg[rt].lazy;
    seg[rt].lazy = 0;
}
void update(int ul, int ur, ll c, int l = 1, int r = nn + 1, int rt = 1)
{
    if(ul <= l && r <= ur){
        seg[rt].lazy = c;
        seg[rt].col = c;
        return;
    }
    push_down(rt);
    int m = l + (r - l) / 2;
    if(ul < m) update(ul, ur, c, lch);
    if(ur > m) update(ul, ur, c, rch);
    push_up(rt);
}
ll query(int ql, int qr, int l = 1, int r = nn + 1, int rt = 1)
{
    if(ql >= r || qr <= l) return 0LL;
    if(ql <= l && r <= qr){
        return seg[rt].col;
    }
    push_down(rt);
    int m = l + (r - l) / 2;
    ll ret = 0ll;
    if(ql < m) ret |= query(ql, qr, lch);
    if(qr > m) ret |= query(ql, qr, rch);
    return ret;
}
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i = 1; i <= n; i++){
        cin >> col[i];
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getinfo(1, 0);
    for(int i = 1; i <= n; i++) update(st[i], st[i] + 1, (1ll << col[i]));
    for(int i = 0; i < m; i++){
        int tp;
        cin >> tp;
        if(tp == 1){
            int v, c;
            cin >> v >> c;
            update(st[v], ft[v], (1ll << c));
        } else {
            int v;
            cin >> v;
            cout << __builtin_popcountll(query(st[v], ft[v])) << endl;
        }
    }
    return 0;
}

