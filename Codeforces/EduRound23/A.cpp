#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int sx, sy, ex, ey;
    int x, y;
    cin >> sx >> sy >> ex >> ey;
    cin >> x >> y;
    int dx = ex - sx;
    int dy = ey - sy;
    bool flag = false;
    if (dx % x == 0 && dy % y == 0) {
        if ((dx / x - dy / y) % 2 == 0) {
                flag = true;
        }
    }
    if (flag) cout << "YES\n";
    else cout <<"NO\n";
    return 0;
}
