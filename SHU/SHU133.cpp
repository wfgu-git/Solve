// f(n)=x*f(n-1)+y*f(n-2)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3;
cosnt int moder = 10007
int ans;
struct Mat {
    int mat[maxn][maxn];
};

Mat operator * (Mat a, Mat b)
{
    Mat t;
    memset(t.mat, 0, sizeof(t.mat));
    for (int k = 0; k < maxn; k++) {
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                t.mat[i][j] += a.mat[i][k] * b.mat[k][j] % moder;
            }
        }
    }
    return t;
}
Mat operator ^ (Mat a, int n)
{
    Mat t;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            t.mat[i][j] = (i == j);
        }
    }

    while (n) {
        if (n & 1)
            t = t * a;
        a = a * a;
        n >>= 1;
    }
    return t;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        ans = 0;
        Mat t.mat = {x, y, 1, 0};
        t = t ^ (n - 1);


    }
    return 0;
}
