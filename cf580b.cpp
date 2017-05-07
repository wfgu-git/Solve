#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, d;
pair<int, int> friends[maxn];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        int m, s;
        cin >> m >> s;
        friends[i] = {m, s};
    }
    sort(friends, friends + n);
    int l = 0, r = 0;
    ll ret = -1, temp = 0;
    while(l < n) {
        while(r < n && friends[r].first - friends[l].first < d) {
            temp += friends[r++].second;
        }
        // cout << temp << endl;
        ret = max(temp, ret);
        temp -= friends[l++].second;
    }
    cout << ret << endl;
    return 0;
}