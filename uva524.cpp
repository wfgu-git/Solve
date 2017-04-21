/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a,b) scanf("%d%d",&a, &b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a, &b, &c)
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) sort(all(x)); v.erase(unique(all(v)), end())
#define mp(a,b) make_pair(a,b)
#define clr(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int N = 1000;
int n, tot = 0;
int prime[N] = {0};
bool isNotPrime[N] = {1, 1};
int ring[20];
bool used[20];
void getPrime() {
    for (int i = 2; i < N; i++) {
        if (isNotPrime[i] == false) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot && prime[j]*i < N; j++) {
            isNotPrime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

// arr ring[]  0 ~ n-1 is the ret of the number  ...n
// !isNotprime[x]  means  x is prime
void dfs(int cur) {
    if (cur == n && !isNotPrime[ring[0] + ring[n - 1]]) {  // need to check the first and the end
        for (int i = 0; i < n; i++) {
            if (i)  printf(" ");
            printf("%d", ring[i]);
        }
        printf("\n");
        return;
    } else {
        for (int i = 2; i <= n; i++) {
            if (!used[i] && !isNotPrime[i + ring[cur - 1]]) {  //
                used[i] = true;
                ring[cur] = i;
                // printf("Debug the %d deepth -->  the chosen number is %d\n", cur, i);
                dfs(cur + 1);
                used[i] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    getPrime();
    // for (int i = 0; i < 1000; i++) {
    //     if (!isNotPrime[i]) {
    //         printf("%d ", i);
    //     }
    // }
    int kase = 0;
    while (~iscanf(n)) {
        if (kase)  printf("\n");
        printf("Case %d:\n", ++kase);
        clr(used, 0), clr(ring, 0);
        ring[0] = 1;
        used[1] = true;
        dfs(1);
    }
    return 0;
}