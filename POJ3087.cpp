/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
// typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a, b) scanf("%d%d", &a, &b)
#define iscanf3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define mo(a, b) (((a) % (b) + (b)) % (b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) \
    sort(all(x)); \
    v.erase(unique(all(v)), end())
#define mp(a, b) make_pair(a, b)
#define clr(x, i) memset(x, i, sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l, m, rt << 1
#define rch m + 1, r, rt << 1 | 1
#define rep(i, x, n) for (int i = x; i < n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 5050;
char s1[maxn], s2[maxn], s12[maxn];
char target[maxn << 1];
map<string, int> check;
bool Cmp(char a[], char b[]) {
    int length = strlen(a);
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[]) {
    int t, kase = 0;
    scanf("%d", &t);
    while (t--) {
        clr(s1, -1), clr(s2, -1), clr(target, -1), clr(s12, -1);
        int n;
        // n --> the length of the string
        scanf("%d", &n);
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", target);

        int cnt = 0;
        bool flag = false;
        while (!flag) {
            int p = 0;
            for (int i = 0; i < n; i++) {
                s12[p++] = s2[i];
                s12[p++] = s1[i];
            }
            s12[p] = '\0';
            cnt++;
            if (Cmp(s12, target) == true) {
                flag = true;
                break;
            }
            string temp = s12;
            if (check.count(temp)) {
                flag = false;
                break;
            } else {
                check[temp] = 1;
            }
            for (int i = 0; i < n; i++) {
                s1[i] = s12[i];
                s2[i] = s12[i + n];
            }
            s1[n] = '\0';
            s2[n] = '\n';
        }
        if (flag)
            printf("%d %d\n", ++kase, cnt);
        else
            printf("%d %d\n", ++kase, -1);
    }
    return 0;
}
