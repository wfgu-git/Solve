#include <bits/stdc++.h>

using namespace std;

int minimumChocolateMoves(int n, vector <int> X) {
    // Complete this function
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if ( (i & 1) != (X[i] & 1) )
            cnt++;

    if (cnt & 1) return -1;


}

int main() {
    //  Return the minimum number of chocolates that need to be moved, or -1 if it's impossible.
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector<int> X(n);
        for(int X_i = 0; X_i < n; X_i++){
           cin >> X[X_i];
        }
        int result = minimumChocolateMoves(n, X);
        cout << result << endl;
    }
    return 0;
}
