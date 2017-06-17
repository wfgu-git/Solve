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
typedef priority_queue<int, vector<int>, greater<int> > pq_int;
typedef priority_queue<PII, vector<PII>, greater<PII> > pq_PII;
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
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 10;
bool used[maxn];
char grid[maxn][maxn];
int n, k, cnt, res;

void solve(int r) {
	if(cnt == k) {
		res++;
		return;
	}
	if(r > n)  return;
	for(int c = 1; c <= n; c++) {
		if(!used[c] && grid[r][c] == '#') {
			used[c] = true;
			cnt++;
			solve(r + 1);
			cnt--;
			used[c] = false;
		}
	}
	solve(r + 1);
}

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	while(~iscanf2(n, k) && (n != -1 && k != -1)) {
		for(int i = 1; i <= n; i++) {
			scanf("%s", grid[i] + 1);
		}

		mset(used, 0);
		cnt = res = 0;
		solve(1);
		printf("%d\n", res);
	}
	return 0;
}

