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
struct Edge {
	int u, v, w;
	void add_edge(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
} edge[1000010];
int a[maxn], b[maxn], c[maxn];
int in[maxn], pre[maxn], vis[maxn], belong[maxn];
int n, x, y, z;
int root;

int get_dis(int i, int j) {
	return abs(a[i] - a[j]) + abs(b[i] - b[j]) + abs(c[i] - c[j]);
}

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	while(~scanf("%d%d%d%d", &n, &x, &y, &z) && x + y + z + n) {

		//input
		int edge_num = root = 0;
		for(int i = 1; i <= n; i++) {
			sc3(a[i], b[i], c[i]);
			edge[edge_num++].add_edge(0, i, c[i] * x);
		}
		int k, vv;
		for(int i = 1; i <= n; i++) {
			sc(k);
			while(k--) {
				sc(vv);
				if(vv == i)  continue;
				int dis = get_dis(i, vv);
				if(c[i] < c[vv]) {
					edge[edge_num++].add_edge(i, vv, dis * y + z);
				} else {
					edge[edge_num++].add_edge(i, vv, dis * y);
				}
			}
		}

		//solve
		int res = 0;
		bool flag = true;
		++n;
		while(true) {
			//init
			for(int i = 0; i <= n; i++) {
				in[i] = INF;
			}

			//find the minimum in_egde of each point
			for(int i = 0; i < edge_num; i++) {
				int u = edge[i].u, v = edge[i].v, w = edge[i].w;
				if(in[v] > w && u != v) {
					pre[v] = u;
					in[v] = w;
				}
			}

			for(int i = 0; i < n; i++) {
				if(in[i] == INF && i != root) {
					flag = false;
				}
			}
			if(!flag)  break;
			int cntcir = 0;
			mset(belong, -1);
			mset(vis, -1);

			//find the cir of the pic
			in[root] = 0;
			for(int i = 0; i < n; i++) {
				res += in[i];
				int v = i;
				while(vis[v] != i && belong[v] == -1 && v != root) {
					vis[v] = i;
					v = pre[v];
				}
				if(v != root && belong[v] == -1) {
					for(int u = pre[v]; u != v; u = pre[u]) {
						belong[u] = cntcir;
					}
					belong[v] = cntcir;
					cntcir++;
				}
			}

			//suo dian
			if(cntcir == 0)  break;
			for(int i = 0; i < n; i++) {
				if(belong[i] == -1) {
					belong[i] = cntcir++;
				}
			}

			for(int i = 0; i < edge_num; i++) {
				int v = edge[i].v;
				edge[i].u = belong[edge[i].u];
				edge[i].v = belong[edge[i].v];
				if(edge[i].u != edge[i].v) {
					edge[i].w -= in[v];
				}
			}

			n = cntcir;
			root = belong[root];
		}

		if(flag)  pt(res);
		else  printf("poor XiaoA\n");
	}
	return 0;
}

