#include <bits/stdc++.h>
using namespace std;

struct goods {
    int p, fc, bc;
} g[200005];
int n, m;
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    set<int> s[4];
    for (int i = 0; i < n; i++) cin >> g[i].p;
    for (int i = 0; i < n; i++) cin >> g[i].fc;
    for (int i = 0; i < n; i++) cin >> g[i].bc;

    for (int i = 0; i < n; i++) {
        goods cur = g[i];
        s[cur.fc].insert(cur.p);
        s[cur.bc].insert(cur.p);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int colr;
        cin >> colr;
        if (s[colr].size() == 0) {
            cout << -1 << " ";
        } else {
            auto it = s[colr].begin();
            int price = *it;
            for (int k = 1;k <= 3; k++) s[k].erase(price);
            cout << price << " ";
        }
    }
    cout << endl;
    return 0;
}

