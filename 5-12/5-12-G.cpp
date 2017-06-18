#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 100;
const double eps = 1e-7;
struct Edge {
    int u, v;
    int d;
    double cost;
    int f;
    Edge() {}
    Edge(int _u, int _v, int _d, int _f): u(_u), v(_v), d(_d), f(_f) {}
} e[maxn];
bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}
int n, m;
long long M;
int fa[maxn];
void init(int x) {for(int i = 0; i <= x; i++)  fa[i] = i;}
int fnd(int x) {
    if(x != fa[x]) {
        fa[x] = fnd(fa[x]);
    }
    return fa[x];
}
bool same(int a, int b) {return fnd(a) == fnd(b);}
double check(double k) {
    // sort
    for(int i = 0; i < m; i++) {
        Edge &cur = e[i];
        if(cur.f == 1) cur.cost = 1.0 * cur.d * k;
        else cur.cost = cur.d;
    }
    sort(e, e + m, cmp);

    //do kruskal
    double ret = 0;
    init(n);
    for(int i = 0; i < m; i++) {
        Edge &cur = e[i];
        if(same(cur.u, cur.v)) continue;
        fa[fnd(cur.v)] = fnd(cur.u);
        ret += cur.cost;
    }
    // printf("%f\n", ret);
    return ret;
}

int main(int argc, char const *argv[]) {
    memset(e, 0, sizeof(e));
    scanf("%d%d%lld", &n, &m, &M);
    for(int i = 0; i < m; i++) {
        int u, v, f, t;
        scanf("%d%d%d%d", &u, &v, &t, &f);
        e[i] = Edge(u, v, t, f);
    }

    // binary search
    double l = 0, r = M;
    while(fabs(r - l) > eps) {
        double mid = l + (r - l) / 2.0;
        if(check(mid) <= M) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%f\n", l);
    return 0;
}
