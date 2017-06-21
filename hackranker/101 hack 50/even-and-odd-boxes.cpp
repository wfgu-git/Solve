#include <bits/stdc++.h>

using namespace std;

int minimumChocolateMoves(int n, vector <int> X) {
    // Complete this function
    vector < int > odd, even;
    set < int > odd_err, even_err;
    int cnt_error = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.push_back(X[i]);
            if (X[i] % 2 != 0) cnt_error++, even_err.insert(i);
        } else {
            odd.push_back(X[i]);
            if (X[i] % 2 == 0) cnt_error++, odd_err.insert(i);
        }
    }
    if (cnt_error & 1) return -1;

    for (set < int > it = even_err.begin(); it != even_err.end(); it++) {
        
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