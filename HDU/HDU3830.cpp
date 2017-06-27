#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node {
    ll x, y, z, d;

    void Sort() {
        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);
    }

    bool operator == (const Node &rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    void show() {
        cout << x << " " << y << " " << z << " " << d << endl;
    }
};
Node start, target;
Node root(Node &u)
{
    Node rt = u;
    ll dep = 0, k;
    while (true) {
        ll s1 = abs(rt.y - rt.x);
        ll s2 = abs(rt.z - rt.y);
        if (s1 == s2) break;
        if (s1 < s2) {
            k = (s2 - 1) / s1;
            rt.x += k * s1;
            rt.y += k * s1;
            dep += k;
        } else {
            k = (s1 - 1) / s2;
            rt.z -= k * s2;
            rt.y -= k * s2;
            dep += k;
        }
    }
    u.d = dep;
    return rt;
}
void update(Node &u, ll dis)
{
    ll cnt = 0;
    while (cnt < dis) {
        ll s1 = abs(u.y - u.x);
        ll s2 = abs(u.z - u.y);
        ll k = abs(cnt - dis);
        if (s1 < s2) {
            ll mv = (s2 - 1) / s1;
            mv = min(mv, k);
            u.x += mv * s1;
            u.y += mv * s1;
            cnt += mv;
            if (mv == k) break;
        } else {
            ll mv = (s1 - 1) / s2;
            mv = min(mv, k);
            u.z -= mv * s2;
            u.y -= mv * s2;
            cnt += mv;
            if (mv == k) break;
        }
    }
    u.d -= dis;
}
ll solve()
{
    Node ts, tt;
    ll l = 0, r = start.d;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll dis = start.d - mid;
        ts = start, tt = target;
        update(ts, dis);
        update(tt, dis);
        if (ts == tt)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 2 * (start.d - r);
}
int main()
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        start.x = a, start.y = b, start.z = c, start.d = 0;
        scanf("%d%d%d", &a, &b, &c);
        target.x = a, target.y = b, target.z = c, target.d = 0;

        start.Sort();
        target.Sort();
        Node ps = root(start);
        Node pt = root(target);
//        start.show();
//        target.show();
//        ps.show();
//        pt.show();
        if (ps == pt) {
            ll dis = abs(start.d - target.d);
            if (start.d > target.d) update(start, dis);
            else update(target, dis);

            ll ans = solve();
            printf("YES\n");
            printf("%lld\n", ans + dis);
        } else {
            printf("NO\n");
        }

    }
    return 0;
}
