#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int n, m;
int g[505][505];
bool row_del(int row) {
	bool flag = true;
	for (int i = 0; i < m; i++) {
		if (g[row][i] <= 0) {
			flag = false;
			break;
		}
	}
	return flag;
}
bool col_del(int col) {
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (g[i][col] <= 0) {
			flag = false;
			break;
		}
	}
	return flag;
}
vector < int > R, C;
int main() {
	ios::sync_with_stdio(false);

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> g[i][j];

		if (m < n) {
			for (int c = 0; c < m; c++) {
				while (col_del(c)) {
					for (int i = 0; i < n; i++) {
						g[i][c]--;
					}
					C.push_back(c + 1);
				}
			}
			for (int r = 0; r < n; r++) {
				while (row_del(r)) {
					for (int i = 0; i < m; i++) {
						g[r][i]--;
					}
					R.push_back(r + 1);
				}
			}

			bool flag = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (g[i][j] != 0)
						flag = false;
				}
			}
			if (!flag) cout << -1 << endl;
			else {
				int ans = R.size() + C.size();
				cout << ans << endl;
				for (auto x : C) cout << "col " << x << endl;
				for (auto x : R) cout << "row " << x << endl;
			}
			continue;
		}
		for (int r = 0; r < n; r++) {
			while (row_del(r)) {
				for (int i = 0; i < m; i++) {
					g[r][i]--;
				}
				R.push_back(r + 1);
			}
		}

		for (int c = 0; c < m; c++) {
			while (col_del(c)) {
				for (int i = 0; i < n; i++) {
					g[i][c]--;
				}
				C.push_back(c + 1);
			}
		}

		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] != 0)
					flag = false;
			}
		}

		if (!flag) cout << -1 << endl;
		else {
			int ans = R.size() + C.size();
			cout << ans << endl;
			for (auto x : R) cout << "row " << x << endl;
			for (auto x : C) cout << "col " << x << endl;
		}
	}
	return 0;
}
