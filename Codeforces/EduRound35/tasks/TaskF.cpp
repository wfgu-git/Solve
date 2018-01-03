/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskF {
	int n;
	vector<vector<int>> T;
	vector<int> depth1, depth2;
	int d, root1, root2;
	void dfs_diameter(int x, int p, int L, int &root) {
		if (L >= d) {
			d = L;
			root = x;
		}
		for (int v : T[x]) {
			if (v != p) {
				dfs_diameter(v, x, L + 1, root);
			}
		}
	}

	void dfs1(int x, int p, int depth) {
		depth1[x] = depth;
		for (int v : T[x]) {
			if (v != p) {
				dfs1(v, x, depth + 1);
			}
		}
	}

	void dfs2(int x, int p, int depth) {
		depth2[x] = depth;
		for (int v : T[x]) {
			if (v != p) {
				dfs2(v, x, depth + 1);
			}
		}
	}


	void solve(std::istream& in, std::ostream& out) {
		in >> n;
		T.clear();
		T.resize(n + 2);

		for (int i = 1; i < n; ++i) {
			int x, y;
			in >> x >> y;
			T[x].push_back(y);
			T[y].push_back(x);
		}

		d = 0;
		dfs_diameter(1, -1, 0, root1);
		dfs_diameter(root1, -1, 0, root2);

		depth1.assign(n + 2, 0);
		dfs1(root1, -1, 0);
		depth2.assign(n + 2, 0);
		dfs2(root2, -1, 0);

		int64_t  ans = 1LL * d * (d + 1) / 2;
		vector<pair<int, int>> V;
		for (int i = 1; i <= n; ++i) {
			if (depth1[i] + depth2[i] == d) continue;

			int dist = max(depth1[i], depth2[i]);
			V.emplace_back(dist, i);
			ans += dist;
		}
		out << ans << "\n";


		sort(V.begin(), V.end(), greater<pair<int, int>>());
		for (auto & pii : V) {
			int v = pii.second;
			if (depth1[v] > depth2[v]) {
				out << root1 << " " << v << " " << v << "\n";
			} else {
				out << root2 << " " << v << " " << v << "\n";
			}
		}
		V.clear();

		for (int i = 1; i <= n; ++i) {
			if (depth1[i] + depth2[i] == d && i != root1) {
				V.emplace_back(depth1[i], i);
			}
		}
		sort(V.begin(), V.end(), greater<pair<int, int>>());
		for (auto & pii : V) {
			out << root1 << " " << pii.second << " " << pii.second << "\n";
		}
	}
};
