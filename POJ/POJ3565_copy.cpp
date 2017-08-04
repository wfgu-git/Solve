//囧，KM都写了顺便改一下吧
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 110;
const double INF = 1e100;
const double EPS = 1e-8;

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

int n;
double mat[MAXN][MAXN], slack[MAXN], Lx[MAXN], Ly[MAXN];
int left[MAXN];
bool S[MAXN], T[MAXN];

bool dfs(int i) {
    S[i] = true;
    for(int j = 1; j <= n; ++j) if(!T[j]) {
        double t = Lx[i] + Ly[j] - mat[i][j];
        if(sgn(t) == 0){
            T[j] = true;
            if(!left[j] || dfs(left[j])){
                left[j] = i;
                return true;
            }
        }
        else slack[j] = min(slack[j],t);
    }
    return false;
}

void update() {
    double a = INF;
    for(int i = 1; i <= n; ++i) if(!T[i])
        a = min(slack[i],a);
    for(int i = 1; i <= n; ++i){
        if(S[i]) Lx[i] -= a;
        if(T[i]) Ly[i] += a; else slack[i] -= a;
    }
}

void KM() {
    for(int i = 1; i <= n; ++i) {
        Lx[i] = Ly[i] = left[i] = 0;
        for(int j = 1; j <= n; ++j) Lx[i] = max(Lx[i], mat[i][j]);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) slack[j] = INF;
        while(true){
            for(int j = 1; j <= n; ++j) S[j] = T[j] = 0;
            if(dfs(i)) break; else update();
        }
    }
    //int ans = 0;
    //for(int i = 1; i <=n; ++i) ans += Lx[i] + Ly[i];
    //return ans;
}

void output() {
    for(int i = 1; i <= n; ++i) printf("%d\n", left[i]);
}

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
    void read() {
        scanf("%d%d", &x, &y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    double operator * (const Point &rhs) const {
        Point a(*this - rhs);
        return sqrt(a.x * a.x + a.y * a.y);
    }
};

Point p1[MAXN], p2[MAXN];

int main() {
    bool flag = true;
    while(scanf("%d", &n) != EOF) {
        if(flag) flag = false; else puts("");
        for(int i = 1; i <= n; ++i) p1[i].read();
        for(int i = 1; i <= n; ++i) p2[i].read();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) mat[j][i] = -(p1[i] * p2[j]);
        }
        KM();
        output();
    }
}
