#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 110;

struct Matrix
{
    int n;
    ll mat[maxn][maxn];

    Matrix(int _n) : n(_n) {}

    void clr() {
        memset(mat, 0, sizeof(mat));
    }
    void unit() {
        clr();
        for (int i = 0; i < n; i++) 
            mat[i][i] = 1;
    }

    Matrix operator * (const Matrix &rhs) {
        Matrix ret(n);
        ret.clr();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    for (int k = 0; k < n; k++) {
                        ret.mat[i][k] += mat[i][j] * rhs.mat[j][k];
                    }
                }
            }
        }
        return ret;
    }

    vector < ll > operator * (const vector < ll > &rhs) {
        vector < ll > ret(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret[i] += mat[i][j] * rhs[j];
            }
        }
        return ret;
    }

    Matrix operator ^ (int b) {
        Matrix ret(n);
        ret.unit();
        Matrix base = *this;

        while (b) {
            if (b & 1) 
                ret = ret * base;
            base = base * base;
            b >>= 1;
        }
        return ret;
    } 

} ;
int main()
{
    int n, m, k;
    char op[5];
    while (~scanf("%d%d%d", &n, &m, &k)) {
        if (!(n + m + k)) break;
        Matrix raw(n + 1);
        raw.unit();
        for (int i = 0; i < k; i++) {
            int id, a, b;
            Matrix tmp(n + 1);
            tmp.unit();
            scanf("%s", op);
            if (op[0] == 'g') {
                scanf("%d", &id);
                tmp.mat[id - 1][n] = 1;
            } else if (op[0] == 'e') {
                scanf("%d", &id);
                tmp.mat[id - 1][id - 1] = 0;
            } else {
                scanf("%d%d", &a, &b);
                tmp.mat[a - 1][a - 1] = 0;
                tmp.mat[b - 1][b - 1] = 0;
                tmp.mat[a - 1][b - 1] = 1;
                tmp.mat[b - 1][a - 1] = 1;
            }
            raw = tmp * raw;
        }

        Matrix ret = raw ^ m;
        vector < ll > col(n + 1), ans(n + 1);
        col[n] = 1;
        ans = ret * col;

        int sz = (int)ans.size();
        for (int i = 0; i < sz - 1; i++) {
            if (i) printf(" ");
            printf("%lld", ans[i]);
            if (i == sz - 2) printf("\n");
        }
    }
    return 0;
}
