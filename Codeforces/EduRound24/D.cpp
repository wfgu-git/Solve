#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
const int maxn = 1e6;
int n, a;
int cnt[maxn + 5];
set < pii > s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a;
    for (int i = 1; i <= maxn; i++) s.insert({0, i});
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (s.count({cnt[c], c})) {
            s.erase({cnt[c], c});
            cnt[c]++;
            s.insert({cnt[c], c});
        }
        while (s.begin()->first < cnt[a]) s.erase(s.begin());
    }
    if (s.begin()->second == a) s.erase(s.begin());
    if (s.size()) {
        cout << s.begin()->second << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
