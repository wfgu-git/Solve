#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C(int n, int r)
{
    if (r < n - r) r = n - r;
    ll ans = 1;
    for (int i = r + 1; i <= n; i++) ans *= i;
    for (int i = 1; i <= n - r; i++) ans /= i;
    return ans;
}
int a[100002];
int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map < int, int > cnt;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
        cnt[temp] ++;
    }
    sort(a, a + n);
    int i = a[0];
    int j = a[1];
    int k = a[2];
    ll ans = 1;
    if (i == j && j == k) {
        ans = C(cnt[i], 3);
    } else if (i != j && i != k && j != k) {
        ans = cnt[i] * cnt[j] * cnt[k];
    } else {
        if (i == j) {
            ans = C(cnt[i], 2) * cnt[k];
        } else if (i == k){
            ans = C(cnt[i], 2) * cnt[j];
        } else {
            ans = C(cnt[j], 2) * cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}

