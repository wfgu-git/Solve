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
typedef vector<int> VI;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define ptlld(a) printf("%lld\n",a)
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

const int maxn = 1010;
int a[maxn];
bool vis[maxn];
//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n, k;
	queue<int> q;
	mset(vis, 0);
	sc2(n, k);
	for(int i = 1; i <= k; i++)  sc(a[i]);
	for(int i = 1; i <= n; i++)  q.push(i);
	for(int i = 1; i <= k; i++) {
		//a[i] = a[i] % (n - i + 1);
		for(int step = 0; step < a[i] % (n - i + 1); step++) {
			q.push(q.front());
			q.pop();
		}
		int cur = q.front();
		q.pop();
		printf("%d\n", cur);
	}
	return 0;
}
