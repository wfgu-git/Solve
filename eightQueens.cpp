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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

const int maxn = 9;
int queen[maxn];
int solveSum;
// queen[index] = value
// index ==> row of the queen
// value ==> col of the queen

bool is_hit(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		if (a[i] == a[n] || abs(a[i] - a[n]) == abs(i - n))
			return true;
	}
	return false;
}

void dfs(int row, int n)
{
	for (int col = 1; col <= n; col++) {
		queen[row] = col;
		if (!is_hit(queen, row)) {
			if (row < n) {
				dfs(row + 1, n);
			} else {
				solveSum++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int n = 8;
	dfs(1, n);
	printf("%d\n", solveSum);
	return 0;
}

