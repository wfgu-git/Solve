#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
const int maxn = 2;
const ll moder = 100000007;
struct Matrix
{
    ll mat[maxn][maxn]; 

    Matrix() {
        memset(mat, 0, sizeof(mat));
    }

    void unit() {
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                mat[i][j] = (i == j);
    }

    void init() {
        mat[0][0] = 1, mat[0][1] = 8;
        mat[1][0] = 1, mat[1][1] = 0;
    } 

    Matrix operator * (const Matrix &rhs) {
        Matrix ans;
        for (int k = 0; k < maxn; k++)
            for(int i = 0; i < maxn; i++) {
                for (int j = 0; j < maxn; j++) {
                    ans.mat[i][j] += mat[i][k] * rhs.mat[k][j] % moder;
                }
            }
            return ans;
    }
} raw;
Matrix operator ^ (Matrix base, ll n)
{
    Matrix ans;
    ans.unit();

    while (n) {
        if (n & 1)
            ans = ans * base;
        base = base * base;
        n >>= 1;
    }

    return ans;
}
const ll col[] = {1, 1};
int main()
{
    ios::sync_with_stdio(false);

    while (cin >> n) {
        if (n == 1 || n == 2){
            cout << 1 << endl;
            continue;
        }

        raw.init();
        Matrix ret = raw ^ (n - 2);
        ll ans = 0;
        for (int i = 0; i < maxn; i++) {
            ans = (ans + ret.mat[0][i] * col[i] % moder) % moder;
        }
        cout << ans << endl;
    }
    return 0;
}
