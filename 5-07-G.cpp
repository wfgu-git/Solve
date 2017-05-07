#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int n;
int a[maxn];
ll c[maxn];
map<int, vector<int> > ls;
int lowbit(int x) { return x & (-x); }

void update(int x) {
    while (x <= n) {
        c[x] += 1;
        x += lowbit(x);
    }
}
ll getsum(int x) {
    ll ret = 0;
    while (x > 0) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int main(void) {
    while (scanf("%d", &n) != EOF) {
        ls.clear();
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ls[a[i]].push_back(i);
        }
        int p = 1;
        for (auto &kv : ls) {
            for (int i = 0; i < (int)kv.second.size(); i++) {
                a[kv.second[i]] = p;
            }
            p++;
        }
        ll ret = 0;
        for (int i = n; i >= 1; i--) {
            ret += getsum(a[i] - 1);
            update(a[i]);
        }
        printf("%lld\n", ret);
    }
    return 0;
}
