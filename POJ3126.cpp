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

const int maxn = 10010;
int tot = 0;
int prime[maxn] = {0};
bool isNotPrime[maxn] = {1, 1};
int dist[maxn];
void getPrime() {
    for(int i = 2; i < maxn; i++) {
        if(!isNotPrime[i])  { // 不是素数
            prime[tot++] = i; // 记录第几个素数是几
        }
        for(int j = 0; j < tot && prime[j]*i < maxn; j++) {
            isNotPrime[i * prime[j]] = true;
            // i == prime    prime[j] < i -->  the ret must not a prime
            // i != prime    prime[j] < i -->  need to stop when prime[j] is the first prime factor of i
            if(i % prime[j] == 0)
                break;
        }
    }
}

int Move(int x, int pos, int k) {
    int ret;
    if(pos == 0) {
        ret = x % 1000;
        ret = ret + k * 1000;
    } else if(pos == 1) {
        ret = (x / 1000) * 1000;
        ret = ret + x % 100;
        ret = ret + k * 100;
    } else if(pos == 2) {
        ret = (x / 100) * 100;
        ret = ret + x % 10;
        ret = ret + k * 10;
    } else {
        ret = (x / 10) * 10;
        ret = ret + k;
    }
    return ret;
}

void Bfs(int start, int target) {
    clr(dist, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == target) return;
        for(int pos = 0; pos < 4; pos++) {
            for(int i = 0; i < 10; i++) {
                if(pos == 0 && i == 0) continue;
                int nx = Move(cur, pos, i);
                // printf("%d\n", nx);
                if(isNotPrime[nx] == true) continue;
                if(dist[nx] == -1) {
                    dist[nx] = dist[cur] + 1;
                    if(nx == target) return;
                    q.push(nx);
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
    getPrime();
    // for(int i = 2; i < 9999; i++) {
    //     if(!isNotPrime[i])
    //         printf("%d is prime\n", i);
    // }
    int t;
    iscanf(t);
    while(t--) {
        int x, target;
        iscanf2(x, target);

        Bfs(x, target);
        printf("%d\n", dist[target]);
    }
    return 0;
}


