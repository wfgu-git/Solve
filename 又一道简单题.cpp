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
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

bool ok[10010];
set<int> res;
int change(int x, int pos, int k)
{
	int res;
	if (pos == 0) {
		res = x % 1000;
		res = res + k * 1000;
	} else if (pos == 1) {
		res = (x / 1000) * 1000;
		res = res + x % 100;
		res = res + k * 100;
	} else if (pos == 2) {
		res = (x / 100) * 100;
		res = res + x % 10;
		res = res + k * 10;
	} else {
		res = (x / 10) * 10;
		res = res + k;
	}
	return res;
}

void solve(int n)
{
	for (int pos = 0; pos < 4; pos++) {
		for (int i = 0; i < 10; i++) {
			if (pos == 0 && i == 0)  continue;
			int x = change(n, pos, i);
			// cout << x << endl;
			if (ok[x])  res.insert(x);
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	mset(ok, 0);
	for (int i = 1; i <= 100; i++)  ok[i * i] = true;
	int T, n, kase = 0;
	iscanf(T);
	while (T--) {
		iscanf(n);
		res.clear();
		solve(n);
		int cnt = (int)res.size();
		if (ok[n])  --cnt;
		printf("Case %d: %d\n", ++kase, cnt);
	}
	return 0;
}
