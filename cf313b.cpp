#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int m, id, cnt;
string str;
int blk[maxn];
int blksz, blkid;
int ans[maxn];
struct query {
    int l, r;
    int id;
} qry[maxn];
bool cmp(query a, query b) {
    if(blk[a.l] == blk[b.l])
        return a.r < b.r;
    else
        return blk[a.l] < blk[b.l];
}

void add(int pos) {
    if(str[pos] == str[pos - 1])
        cnt++;
}

void del(int pos) {
    if(str[pos] == str[pos - 1])
        cnt--;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> str >> m;
    int n = (int)str.size();
    blksz = ceil(sqrt(1.0 * n));
    for(int i = 1; i <= n; i++) {
        blk[i] = (i - 1) / blksz;
    }
    for(int i = 0; i < m; i++) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    sort(qry, qry + m, cmp);
    int l , r;
    l = r = 0;
    cnt = 0;
    for(int i = 0; i < m; i++) {
        id = qry[i].id;
        while(r + 1 < qry[i].r) add(++r);
        while(r + 1 > qry[i].r) del(r--);
        while(l < qry[i].l) del(l++);
        while(l > qry[i].l) add(--l);
        ans[id] = cnt;

        //debug
        // cout << "(" << qry[i].l << ", " << qry[i].r << ") = " << cnt << endl;
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}