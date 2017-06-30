#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1111;
struct Point {
    int x, y;
    int dis(const Point &rhs) const  {
        int dx = x - rhs.x;
        int dy = y - rhs.y;
        return dx * dx + dy * dy;
    }
    Point() {}
    Point(int a, int b) : x(a), y(b) {}
} point[maxn + 5];
int n, d;
int fa[maxn + 5];
void init(const int &n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int fnd(int x) {
    if (x != fa[x]) fa[x] = fnd(fa[x]);
    return fa[x];
}
void merge(int a, int b) {
    int dis = point[a].dis(point[b]);
    a = fnd(a);
    b = fnd(b);
    if (dis <= d * d && a != b) {
        fa[a] = b;
    }
}
bool vis[maxn + 5];
int main() {
    cin >> n >> d;
    init(n);
    for (int i = 1; i <= n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    memset(vis, 0, sizeof(vis));
    char op;
    int a, b;
    while (cin >> op) {
        if (op == '0') {
            cin >> a;
            vis[a] = true;
            for (int i = 1; i <= n; i++) {
                if (i == a) continue;
                if (!vis[i]) continue;
                merge(a, i);
            }
        } else {
            cin >> a >> b;
            if (fnd(a) == fnd(b)) {
                cout << "SUCCESS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}