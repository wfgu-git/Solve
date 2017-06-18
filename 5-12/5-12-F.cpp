#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
struct interval {
    int l, r, cnt;
} road[maxn];
bool cmp(interval a, interval b) {
    return a.r < b.r;
}
int nn;
int seg[maxn << 2];
bool vis[maxn];
void update(int p, int k, int l = 1, int r = nn + 1, int rt = 1) {
    if(p == l && l + 1 == r) {
        seg[rt] = k;
        return;
    }
    int m = l + (r - l) / 2;
    if(p < m) update(p, k, l, m, rt << 1);
    else update(p, k, m, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

int query(int L, int R, int l = 1, int r = nn + 1 , int rt = 1) {
    if(L <= l && r <= R) {
        return seg[rt];
    }
    int m = l + (r - l) / 2;
    int ret = 0;
    if(L < m) ret += query(L, R, l, m, rt << 1);
    if(R > m) ret += query(L, R, m, r, rt << 1 | 1);
    return ret;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        memset(seg, 0, sizeof(seg));
        memset(vis, 0, sizeof(vis));
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        nn = n;
        for(int i = 0; i < k; i++) {
            int p;
            scanf("%d", &p);
            update(p, 1);
            vis[p] = true;
        }

        bool flag = true;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &road[i].l, &road[i].r, &road[i].cnt);
            if(road[i].r - road[i].l + 1 < road[i].cnt) flag = false;
        }
        if(!flag) {printf("Case %d: %d\n", kase, -1); continue;}

        sort(road, road + m, cmp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int l = road[i].l;
            int r = road[i].r;
            int cnt = road[i].cnt;

            int temp = query(l, r + 1);
            if(temp >= cnt) continue;
            for(int p = r; p >= l; p--) {
                if(!vis[p]) {
                    vis[p] = true;
                    update(p, 1);
                    temp++, ans++;
                }
                if(temp == cnt) break;
            }
        }
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}