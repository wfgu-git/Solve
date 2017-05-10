#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n, m;
int a[maxn], b[maxn];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);
    int cnt = 0;
    int p, q;
    p = q = 0;
    while(p < n && q < m) {
        if(abs(a[p] - b[q]) < 2) {
            // cout << "a new pair  " << a[p] << ", " << b[q] << endl;
            cnt++, p++, q++;
        } else {
            if(a[p] < b[q]) p++;
            else q++;
        }
    }
    cout << cnt << endl;
    return 0;
}