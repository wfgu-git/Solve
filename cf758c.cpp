// I'm so naive...
// such a easy problem...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = LONG_LONG_MAX;
// const ll INF = LONG_MAX;
ll n, m, k;
int x, y;
ll cnt[105][105];
void getRet(ll &maxi, ll &mini) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            maxi = max(maxi, cnt[i][j]);
            mini = min(mini, cnt[i][j]);
        }
    }
}
void Debug() {
    cout << endl;
    for(int i = 1; i <= n; i++) {
        cout << endl;
        for(int j = 1; j <= m; j++) {
            cout << cnt[i][j] << " ";
        }
    }
    cout << endl;
}
int main(int argc, char const *argv[]) {
    cin >> n >> m >> k >> x >> y;
    ll t;
    t = (n == 1 ? m : (n * m) + (n - 2) * m);
    ll avg = k / t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 || i == n)  cnt[i][j] = avg;
            else cnt[i][j] = 2 * avg;
        }
    }

    // Debug();

    int left = k % t;
    if(left) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[i][j]++;
                if(!--left)
                    break;
            }
            if(!left)
                break;
        }
    }
    // Debug();
    // cout << left << endl;
    if(left) {
        for(int i = n - 1; i >= 2; i--) {
            for(int j = 1; j <= m; j++) {
                cnt[i][j]++;
                if(!--left)
                    break;
            }
            if(!left)
                break;
        }
    }
    // Debug();
    ll retMax = -INF, retMin = INF;
    getRet(retMax, retMin);
    cout << retMax << " " << retMin << " " << cnt[x][y] << endl;
    return 0;
}