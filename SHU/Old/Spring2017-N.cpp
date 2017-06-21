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


const int maxn = 20;
int a[maxn];
int T, n, m, ret;
void dfs(int cur_idx, int cur_num, int deep) {
	if(deep == m) {
		ret = Max(ret, cur_num);
		return;
	}
	if(cur_idx == n) return;
	dfs(cur_idx + 1, cur_num * a[cur_idx], deep + 1);
	dfs(cur_idx + 1, cur_num, deep);
}

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	iscanf(T);
	while(T--) {
		clr(a, 0);
		iscanf2(n, m);
		ret = -INF;
		for(int i = 0; i < n; i++) {
			iscanf(a[i]);
		}
		dfs(0, 1, 0);
		printf("%d\n", ret);
	}
	return 0;
}

