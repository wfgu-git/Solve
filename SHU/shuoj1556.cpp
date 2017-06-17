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
#define sc3(a,c,b) scanf("%d%d%d",&a,&b,&c)
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

int t;
int pic[15][15];
bool vis[10];
bool mark;
bool legal(int r, int c)
{
	if(r < 1 || r > 9 || c < 1 || c > r)  return false;
	return true;
}

void dfs(int r, int c, int num, bool vis[])
{
	bool v[10];
	for(int i = 1; i <= 9; i++)
		v[i] = vis[i];
	if(v[pic[r][c]] == true)
		return ;
	v[pic[r][c]] = true;
	num++;
	if(num == 9) {
		mark = true;
		return ;
	}
	if(legal(r + 1, c))  dfs(r + 1, c, num, v);
	if(legal(r + 1, c + 1))  dfs(r + 1, c + 1, num, v);

}

//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int kase = 0;
	sc(t);
	while(t--) {
		printf("Case %d:\n", ++kase);
		mset(pic, 0);
		for(int i = 1; i <= 9; i++) {
			for(int j = 1; j <= i; j++) {
				sc(pic[i][j]);
			}
		}

		mset(vis, 0);
		mark = false;
		int num = 0;
		dfs(1, 1, num, vis);
		if(mark)  printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}