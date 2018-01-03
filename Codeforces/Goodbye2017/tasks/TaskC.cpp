#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const int inf = 0x3f3f3f3f;
class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, r;
		in >> n >> r;
		vector<int> x;
    x.resize(n);

		for (int i = 0; i < n; ++i) {
			in >> x[i];
		}

		vector<double> ansy(n, 0);

		for (int i = 0; i < n; ++i) {
			double ret = r;

			for (int j = 0; j < i; ++j) {
				int dx = abs(x[i] - x[j]);
				if (dx > 2 * r) continue;
				ret = max(ret, ansy[j] + sqrt(4.0 * r * r - 1.0* dx * dx));
			}
			ansy[i] = ret;
		}

		for (double  x : ansy) {
			out << setprecision(10) << x << " ";
		}
	}
};
