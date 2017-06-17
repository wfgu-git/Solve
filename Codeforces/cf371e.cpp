// I'm too naive.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 3333333;
struct subway {
    ll x;
    int ori, cur;
};
bool cmp(subway a, subway b) {
    return a.x < b.x;
}
subway a[maxn];
ll cum[maxn];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i].x = x;
        a[i].ori = i;
    }
    cin >> k;
    a[0].x = 0;
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++)  a[i].cur = i;
    cum[0] = 0;
    for(int i = 1; i <= n; i++)  cum[i] = cum[i - 1] + a[i].x; // 前缀和

    int l, r, st, en;
    ll sum = 0, ret;
    // for(int i = 2; i <= k; i++) {
    //     for(int j = 1; j < i; j++) {
    //         sum += a[i].x - a[j].x;
    //     }
    // }

    // init sum
    for(int i = 2; i <= k; i++) {
        sum += a[i].x - cum[i - 1];
    }

    // cout << sum << endl;
    // two pointer
    st = l = 1, en = r = k, ret = sum;
    while(r < n) {
        sum += (k - 1) * (a[r + 1].x + a[l].x);
        sum -= (cum[r] - cum[l]);
        sum -= (cum[r] - cum[l]);
        l++, r++;
        if(ret > sum) {
            ret = sum;
            st = l;
            en = r;
        }
    }

    // cout << ret << endl;
    for(int i = st; i <= en; i++) {
        if(i != st) cout << " ";
        cout << a[i].ori;
    }
    cout << endl;
    return 0;
}