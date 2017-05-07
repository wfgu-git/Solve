#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int l, r;
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0, need = 0, temp = 0;
    l = r = 0;
    while(l < n) {
        while(r < n && need + a[r] <= t) {
            need += a[r++];
            temp++;
        }
        cnt = max(temp, cnt);
        need -= a[l++];
        --temp;
    }
    cout << cnt << endl;
    return 0;
}