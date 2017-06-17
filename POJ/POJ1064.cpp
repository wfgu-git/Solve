#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double ld;
ld a[10002];
const int inf = 0x3f3f3f3f;
int n, k;
inline int check(ld x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cnt += floor(a[i] / x);
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        ld l = (ld)0, r = (ld)inf;
        for (int i = 0; i < 200; i++){
            ld mid = l + (r - l) / 2.0;
            if(check(mid) >=k)
                l = mid;
            else
                r = mid;
        }
        cout << fixed << setprecision(2) << (int)floor(r * 100.0) * 1.0 / 100 << endl;
    }
    return 0;
}

