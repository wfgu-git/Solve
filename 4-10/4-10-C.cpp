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

int minv[25], mins[25];
int n, m, res;
void dfs(int s, int v, int layer, int r, int h)
{
	if(layer == 0) {
		if(v == n && s < res)
			res = s;

		return;
	}
	if(v + minv[layer - 1] > n)  return;
	if(s + mins[layer - 1] > res)  return;
	if(s + 2 * (n - v) / r > res)  return; //难点

	for(int i = r; i >= layer; i--) {
		if(layer == m)  s = i * i;
		int curMaxh = Min(h, (n - v - minv[layer - 1]) / (i * i));
		for(int j = curMaxh; j >= layer; j--) {
			dfs(s + 2 * i * j, v + i * i * j, layer - 1, i - 1, j - 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	minv[0] = mins[0] = 0;
	for(int i = 1; i <= 20; i++) {
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	}

	while(scanf("%d%d", &n, &m) == 2) {
		res = INF;
		dfs(0, 0, m, (int)sqrt(1.0 * n), n);

		if(res == INF)  printf("0\n");
		else  printf("%d\n", res);
	}
	return 0;
}

