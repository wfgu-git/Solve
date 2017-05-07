#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int a[550];
int main(void) {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = k;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] + a[i - 1] >= k) continue;
        else {
            int walkNeed = k - a[i] - a[i - 1];
            cnt += walkNeed;
            a[i] += walkNeed;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++) {
        if(i != 1) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
