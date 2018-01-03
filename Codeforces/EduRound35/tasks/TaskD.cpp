/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskD {
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		vector<int> a;
		a.resize(n);

		for (int i = 0; i < n; ++i) {
			in >> a[i];
		}

		int k = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (a[i] > a[j]) {
					k ^= 1;
				}
			}
		}

		int m;
		in >> m;
		for (int i = 0; i < m; ++i) {
			int l, r;
			in >> l >> r;
			--l;
			--r;
			int size = (r - l + 1);
			if (1LL * size * (size - 1) / 2LL & 1) {
				k ^= 1;
			} else {
				;
			}

			if (k & 1) {
				out << "odd\n";
			} else {
				out << "even\n";
			}
		}
		out.flush();
	}
};
