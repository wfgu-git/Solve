#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000;
struct Point {int x, y;} point[maxn + 5];
int fa[maxn + 5];
int getd(const Point &a, const Point &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}
void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int fnd(int x) {
    if (x != fa[x]) fa[x] = fnd(fa[x]);
    return fa[x];
}
void merge(int a, int b, int maxd) {
    int d = getd(point[a], point[b]);
    a = fnd(a);
    b = fnd(b);
    if (d <= maxd * maxd && a != b) fa[a] = b;
}
bool vis[maxn + 5];
int main() {
    int n, maxd;
    cin >> n >> maxd;
    for (int i = 1; i <= n; i++) cin >> point[i].x >> point[i].y; 
    init(n);
    char op;
    while (cin >> op) {
        if (op == 'O') {
            int x;
            cin >> x;
            vis[x] = true;
            for (int i = 1; i <= n; i++) {
                if (i != x && vis[i]) merge(i, x, maxd);
            }
        } else {
            int a, b;
            cin >> a >> b;
            if (fnd(a) == fnd(b)) cout << "SUCCESS" << endl;
            else cout << "FAIL" << endl;
        }
    }
    return 0;
}
