#include <bits/stdc++.h>
using namespace std;

int n, k;
int g[105][105];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k >n * n) cout << -1 << endl;
    else {
        int i = 0, j = 0;
        for(int i = 0; i < n && k; i++){
            g[i][i] =1, k--;
            for(int j = i + 1; j < n && k >= 2; j++, k-=2) g[i][j] = g[j][i] = 1;
        }

        for(int i = 0; i < n; i++){
            if(i) cout << endl;
            for(int j = 0; j < n; j++){
                cout << g[i][j] << " ";
            }
        }
    }
    return 0;
}

