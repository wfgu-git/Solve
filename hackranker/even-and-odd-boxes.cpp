#include <bits/stdc++.h>

using namespace std;

int minimumChocolateMoves(int n, vector <int> X) {
    // Complete this function
    int cnt = 0;
    set < int > wrong, one;
    for (int i = 0; i < n; i++) {
        if ((X[i] & 1) != (i & 1)) {
            // cout << "(" << X[i] << ", " << i << ")" << endl;
            cnt++;
            if (X[i] == 1) one.insert(i);
            else wrong.insert(i);
        }
    }

    // cout << cnt << " errors" << endl;
    if (cnt & 1) return -1;
    
    int ans = 0;
    while (!one.empty() && !wrong.empty()) {
        int a = *one.begin();
        one.erase(one.begin());
        int b = *wrong.begin();
        wrong.erase(wrong.begin());
        X[a]++, X[b]--, ans++;
    }

    if ((int)wrong.size() & 1) return -1;
    if ((int)one.size() & 1) return -1;

    while (wrong.size() >= 2) {
        int a = *wrong.begin();
        wrong.erase(wrong.begin());
        int b = *wrong.begin();
        wrong.erase(wrong.begin());
        X[a]++, X[b]--, ans++;
    }
    
    for (int i = 0; i < n; i++) {
        if (one.empty()) break;
        while ((X[i] & 1) == (i & 1) && X[i] > 2) {
            int a = *one.begin();
            one.erase(one.begin());
            int b = *one.begin();
            one.erase(one.begin());
            X[a]++, X[b]++, X[i] -= 2, ans += 2;
            if (one.empty()) break;
        }
    }
    if (!one.empty()) return -1;
    for (int i = 0; i < n; i++) {
        if ((X[i] & 1) != (i & 1))
            return -1;
    }
    return ans;
}

int main() {
    //  Return the minimum number of chocolates that need to be moved, or -1 if it's impossible.
    int q;
    cin >> q;
    for (int a0 = 0; a0 < q; a0++) {
        int n;
        cin >> n;
        vector<int> X(n);
        for (int X_i = 0; X_i < n; X_i++) {
            cin >> X[X_i];
        }
        int result = minimumChocolateMoves(n, X);
        cout << result << endl;
    }
    return 0;
}