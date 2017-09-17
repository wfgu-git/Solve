#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 500;
int N, M, ret;
int dist[maxn][maxn];
int grid[maxn][maxn];
void init() {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			dist[i][j] = inf;
			grid[i][j] = inf;
		}
		grid[i][i] = dist[i][i] = 0;
	}
}
void Floyd() {
	ret = inf;
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i < k; i++) {
			for(int j = i + 1; j < k; j++) {
				ret = min(ret, dist[i][j] + grid[i][k] + grid[k][j]);
			}
		}

		for(int i = 1; i <= N; i++) {
			// if(i == k)  continue;
			for(int j = 1; j <= N; j++) {
				// if(i == j || j == k)  continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
