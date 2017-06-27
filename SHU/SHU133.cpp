#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4;
const ll moder = 10007;
struct Matrix
{
    ll mat[maxn][maxn];

    void unit() {
        for (int i = 0; i < maxn; i++) 
            for (int j = 0; j < maxn; j++)
                mat[i][j] = (i == j);
    }

    void init(const ll &x, const ll &y) {
        mat[0][0] = 1, mat[0][1] = x * x % moder, mat[0][2] = y * y % moder, mat[0][3] = 2 * ((x * y) % moder) % moder;
        mat[1][0] = 0, mat[1][1] = x * x % moder, mat[1][2] = y * y % moder, mat[1][3] = 2 * ((x * y) % moder) % moder;
        mat[2][1] = 1;
        mat[3][1] = x % moder,  mat[3][3] = y % moder;
    }

    Matrix operator * (const Matrix &rhs) {
        Matrix ans;
        for (int k = 0; k < maxn; k++)
            for (int i = 0; i < maxn; i++) {
                for (int j = 0; j < maxn; j++) {
                    ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k] * rhs.mat[k][j] % moder)) % moder;
                }
            }
        
        return ans;
    }

    Matrix() {
        memset(mat, 0, sizeof(mat));
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
ll n, x, y;
const ll col[] = {1, 1, 1, 1};
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> x >> y;
        raw.init(x, y);
        ll t = n - 1; 
        Matrix ret = raw ^ t; 
        ll ans = 0;
        for (int i = 0; i < maxn; i++) {
            ans = (ans + ret.mat[0][i] * col[i] % moder) % moder;
        }
        cout << ans << endl;
    }
    return 0;
}