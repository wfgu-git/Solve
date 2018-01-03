/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskE {
	void solve(std::istream& in, std::ostream& out) {
		vector<int> S;
		vector<int> ans;
		int n, k;
		in >> n >> k;

		int num = 1;
		S.push_back(n + 1);
		for (int i = 0; i < k; ++i) {
			int x;
			in >> x;

			if (x > S.back()) {
				out << -1;
				return;
			}

			ans.push_back(x);
			S.push_back(x);

			while (!S.empty() && S.back() == num) {
				S.pop_back();
				++num;
			}
		}

		while ((int)ans.size() < n) {
			ans.push_back(S.back() - 1);
			S.push_back(S.back() - 1);

			while (!S.empty() && S.back() == num) {
				S.pop_back();
				++num;
			}
		}

		for (int x : ans) {
			out << x << " ";
		}
		out.flush();
	}
};
