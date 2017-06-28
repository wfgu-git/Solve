#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector < int > vec;
typedef vector < vec > mat;
int n, moder, k;
mat Mul(const mat &a, const mat &b)
{
    mat ans(a.size(), vec(b[0].size()));
    for (int k = 0; k < b.size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b[0].size(); j++) {
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % moder) % moder;
            }
        }
    }
    return ans;
}
mat Pow(mat base, int n)
{
    mat ans(base.size(), vec(base.size()));

    for (int i = 0; i < ans.size(); i++)
        ans[i][i] = 1;

    while (n) {
        if (n & 1)
            ans = Mul(ans, base);
        base = Mul(base, base);
        n >>= 1;
    }
    return ans;
}
int main()
{
    while (scanf("%d%d%d", &n, &k, &moder) == 3) {
        mat a(n, vec(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        mat raw(n * 2, vec(n * 2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                raw[n + i][n + j] = a[i][j];
            }
            raw[i][i] = 1;
            raw[i][n + i] = 1;
        }

        mat ret = Pow(raw, k + 1);
        mat col(n * 2, vec(n));
        for (int i = 0; i < n; i++) {
            col[n + i][i] = 1;
        }
        ret = Mul(ret, col);
        for (int i = 0; i < n; i++) {
            if (i) printf("\n");
            for (int j = 0; j < n; j++) {
                int now = ret[i][j] % moder;
                if (i == j) now = (now + moder - 1) % moder;
                if (j) printf(" ");
                printf("%d", now);
            }
        }
        printf("\n");
    }
    return 0;
}

