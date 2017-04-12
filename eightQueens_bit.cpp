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

const int n = 16;
int upper_limit = (1 << n) - 1;
int res;

void dfs(int row, int ld, int rd)
{
	int pos, p;
	if (row != upper_limit)  {
		pos = upper_limit & ~(row | ld | rd);
		while (pos != 0) {
			p = pos & (-pos);  // the position p is used
			pos = pos ^ p;     // del potition p from pos
			dfs(row | p, (ld | p) << 1, (rd | p) >> 1);
		}
	} else {
		++res;
	}
}

int main(int argc, char const *argv[])
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);

	dfs(0, 0, 0);
	cout << res << endl;
	return 0;
}
