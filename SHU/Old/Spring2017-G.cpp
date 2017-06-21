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

map<int, bool> check;
bool used[50050];
int a[4];
int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> t) {
		check.clear();
		clr(used, 0);
		int cnt = 0;
		for(int i = 0; i < 4; i++) {
			for(int k = 1, p = a[i]; p <= t; p = a[i] * (++k)) {
				if(a[i] > t) break;
				if(check[p] && !used[p]) {
					cnt++;
					used[p] = true;;
				} else {
					check[p] = true;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

