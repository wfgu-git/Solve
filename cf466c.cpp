#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500050;
int a[maxn];
ll cnt[maxn];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll sum = 0;
    cnt[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 3 != 0)  {
        cout << 0 << endl;
    } else {
        sum /= 3;
        ll s = 0, ret = 0;
        for(int i = n; i >= 1; i--) {
            s += a[i];
            if(s == sum)
                cnt[i] = 1;
        }
        for(int i = n - 1; i >= 1; i--)
            cnt[i] += cnt[i + 1];

        s = 0;
        for(int i = 1; i + 2 <= n; i++) {
            s += a[i];
            if(s == sum)
                ret += cnt[i + 2];
        }
        cout << ret << endl;
    }
    return 0;
}
