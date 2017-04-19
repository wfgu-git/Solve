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

//gcd lcm
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
const int maxn = 2000020;
int prime[maxn] = {0}, num = 0;
int isNotPrime[maxn] = {1, 1};

void getPrime() {
    for (int i = 2; i < maxn; i++) {
        if (!isNotPrime[i]) {
            prime[num++] = i;
        }
        for (int j = 0; j < num && i * prime[j] < maxn; j++) {
            isNotPrime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int n;
    while (iscanf(n) != EOF) {
        if (n == 1) {
            printf("0\n");
            continue;
        }
        if (n == 2 || n == 3) {
            printf("1\n");
            continue;
        }

        if (n % 2 == 0) {
            printf("2\n");
            continue;
        }
        if (isPrime(n) == true) {
            printf("1\n");
        } else if (isPrime(n - 2) == true) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
    return 0;
}