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


int L, R, C;
char pic[35][35][35];
//[level][row][column]

void dfs(int layer, int r, int c, int step) {

}

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	while(iscanf3(L, R, C) == 3 && (L + R + C)) {
		for(int l = 0; l < L; l++) {
			for(int r = 0; r < R; r++) {
				scanf("%s", pic[l][r]);
			}
		}

		int step = 0;
		for(int i = 0; i < L; i++) {
			for(int j = 0; j < R; j++) {
				for(int k = 0; k < C; k++) {
					if(pic[i][j][k] == 'S') {
						dfs(i, j, k, step);
					}
				}
			}
		}

		if(!flag)  printf("Trapped!\n");
		else  printf("Escaped in %d minute(s).\n", step);
	}
	return 0;
}

