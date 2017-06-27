#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 4;
const int moder = 100000007;
ll n;
ll col[] = {1, 1, 3, 1};
struct Matrix
{
    ll mat[maxn][maxn];   

    void init() {
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++) 
                mat[i][j] = (i == j);
    }
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
    void init_val() {
        mat[0][0] = 1, mat[0][1] = 1, mat[0][2] = 1;
        mat[1][0] = 1, mat[2][2] = 1, mat[3][3] = 1;
        mat[2][3] = 1;
    }

    Matrix operator * (const Matrix &rhs) const {
        Matrix ans;
        for (int k = 0; k < maxn; k++)
            for (int i = 0; i < maxn; i++) {
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
    ans.init();

    while (n) {
        if (n & 1)
            ans = ans * base;

        base = base * base;
        n >>= 1;
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);

    while (cin >> n) {
        raw.init_val();
        if (n == 1 || n == 2) {
            cout << 1 << endl;
            continue;
        }

        ll t = n - 2;
        Matrix ret = raw ^ t;
        ll ans = 0;
        for (int c = 0; c < maxn; c++) 
            ans = (ans + col[c] * ret.mat[0][c] % moder) % moder;
        cout << ans << endl;
    }
    return 0;
}
