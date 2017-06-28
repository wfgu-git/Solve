#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 16;
int n;
int moder;
struct Matrix
{
    ll mat[maxn][maxn];

    void unit() {
        for (int i = 0; i < maxn; i++) {
            mat[i][i] = 1;
        }
    }

    void init() {
        mat[0][0] = 1, mat[0][3] = 1, mat[0][9] = 1, mat[0][12] = 1, mat[0][15] = 1;
        mat[1][2] = 1, mat[1][8] = 1, mat[1][14] = 1;
        mat[2][1] = 1, mat[2][13] = 1;
        mat[3][0] = 1, mat[3][12] = 1;
        mat[4][8] = 1, mat[4][11] = 1;
        mat[5][10] = 1;
        mat[6][9] = 1;
        mat[7][8] = 1;
        mat[8][1] = 1, mat[8][4] = 1, mat[8][7] = 1;
        mat[9][6] = 1, mat[9][0] = 1;
        mat[10][5] = 1;
        mat[11][4] = 1;
        mat[12][0] = 1, mat[12][3] = 1;
        mat[13][2] = 1;
        mat[14][1] = 1;
        mat[15][0] = 1;
    }

    Matrix operator * (const Matrix &rhs) {
        Matrix ans;
        for (int k = 0; k < maxn; k++) {
            for (int i = 0; i < maxn; i++) {
                for (int j = 0; j < maxn; j++) {
                    ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k] * rhs.mat[k][j] % moder)) % moder;
                }
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
bool isfill[2][4];
void dfs(int s, int dep)
{
    if (dep == 4) {
        int t = 0;
        for (int i = 0; i < 4; i++) {
            if (isfill[1][i]) {
                t |= 1 << i;
            }
        }
        raw.mat[s][t]++;
        return;
    }

    if (isfill[0][dep]) {
        dfs(s, dep + 1);
        return;
    }

    if (dep < 3 && !isfill[0][dep + 1]) {
        isfill[0][dep] = isfill[0][dep + 1] = true;
        dfs(s, dep + 1);
        isfill[0][dep] = isfill[0][dep + 1] = false;
    }
    isfill[0][dep] = isfill[1][dep] = true;
    dfs(s, dep + 1);
    isfill[0][dep] = isfill[1][dep] = false;
}
int main()
{
    for (int i = 0; i < 16; i++) {
        memset(isfill, 0, sizeof(isfill));
        for (int j = 0; j < 4; j++) {
            if ((i >> j) & 1) {
                isfill[0][j] = true;
            }
        }
        dfs(i, 0);
    }

    while (scanf("%d%d", &n, &moder) == 2) {
        if (n + moder == 0) break;
        Matrix ret = raw ^ n;
        printf("%lld\n", ret.mat[0][0] % moder); 
    }
    return 0;
}