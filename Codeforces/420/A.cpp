#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
int a[maxn + 2][maxn + 2];
int g[maxn + 2][maxn + 2];
int main()
{
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int row, col;
        int val;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 1) {
                    row = i;
                    col = j;
                    val = a[i][j];
                    for (int p = 0; p < n; p++) {
                        for (int q = 0; q < n; q++) {
                            if (p == col || q == row) continue;
                            if (a[row][p] + a[q][col] == val) g[i][j] = 1;
                        }
                    }
                } else {
                    g[i][j] = 1;
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] != 1)
                    flag = false;
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}