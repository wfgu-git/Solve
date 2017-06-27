#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int moder = 10007;
const int maxn = 3;
struct Matrix
{
    int mat[maxn][maxn];

    void unit() {
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                mat[i][j] = (i == j);
    }

    void init() {
        mat[0][0] = 2, mat[0][1] = 1;
        mat[1][0] = 2, mat[1][1] = 2, mat[1][2] = 2;
        mat[2][1] = 1, mat[2][2] = 2;
    }

    Matrix operator * (const Matrix &rhs) {
        Matrix ans;
        for (int k = 0; k < maxn; k++)
            for (int i = 0; i < maxn; i++) {
                for (int j = 0; j < maxn; j++) {
                    ans.mat[i][j] = ((ll)ans.mat[i][j] + ((ll)mat[i][k] * (ll)rhs.mat[k][j] % moder)) % moder;
                }
            }

        return ans;
    }

    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
} raw;
Matrix operator ^ (Matrix base, int n)
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
const int col[] = {1, 0, 0};
int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        int n;
        cin >> n;
        raw.init();

        Matrix ret = raw ^ n;
        int ans = ret.mat[0][0] % moder;
        cout << ans << endl;
    }
    return 0;
}

