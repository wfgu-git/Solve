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
typedef long long ll;
// typedef __int64 ll;
typedef pair<int, int> PII;
#define cntOne(x) __builtin_popcount(x)
#define iscanf(a) scanf("%d",&a)
#define iscanf2(a,b) scanf("%d%d",&a,&b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
int sum = 0;
const int maxn = 1e5 + 10;
struct Ans {
	int max = -INF, min = INF, value = 0;
};

Ans st[maxn << 2];

void Pushup(int rt) {
	st[rt].value = st[rt << 1].value + st[rt << 1 | 1].value;
	st[rt].max = Max(st[rt << 1].max, st[rt << 1 | 1].max);
	st[rt].min = Min(st[rt << 1].min, st[rt << 1 | 1].min);
}
void Build(int l, int r, int rt) {
	if(l == r) {
		int v;
		iscanf(v);
		st[rt].value = st[rt].min = st[rt].max = v;
		return;
	}
	int m = (l + r) / 2;
	Build(lch);
	Build(rch);
	Pushup(rt);
}

// update one point
void Modify(int p, int k, int l, int r, int rt) {
	if(l == r) {
		st[rt].value += k;
		st[rt].max += k;
		st[rt].min += k;
		return;
	}
	int m = (l + r) / 2;
	if(p <= m)  Modify(p, k, lch);
	else  Modify(p, k, rch);
	Pushup(rt);
}

Ans Query(int L, int R , int l, int r, int rt) {
	if(l >= L && r <= R) {
		return st[rt];
	}
	int m = (l + r) / 2;
	Ans ret, retl, retr;
	if(L <= m)   {
		retl = Query(L, R, lch);
		// sum += temp.value;
	}
	if(R > m) {
		retr = Query(L, R, rch);
		// sum += temp.value;
	}
	ret.max = Max(retl.max, retr.max);
	ret.min = Min(retl.min, retr.min);
	ret.value = retl.value + retr.value;
	return ret;
}

int main(int argc, char const *argv[]) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, t;
	iscanf2(n, t);
	Build(1, n, 1);
	for(int i = 0; i < t; i++) {
		int tag, p, k;
		iscanf3(tag, p, k);
		if(tag == 1) {
			Modify(p, k, 1, n, 1);
		} else if(tag == 2) {
			printf("%d %d %d\n", Query(p, k, 1, n, 1).max, Query(p, k, 1, n, 1).value, Query(p, k, 1, n, 1).min);
		}
	}
	return 0;
}

