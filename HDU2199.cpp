#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;
const double DNF = 1e15 * 1.0;
double calc(double x) {
    return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
}

bool cmp(double x, double y) {
    if(fabs(x - y) < eps) return true;
    return false;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        double y;
        cin >> y;

        if(y > calc(100.0) || y < calc(0)) {
            cout << "No solution!\n";
        } else {
            double l = 0, r = 100.0;
            while(l + eps < r) {
                double m = l + (r - l) / 2.0;
                double temp = calc(m);
                // cout << "f(" << m << ")" << " = " <<  temp << endl;
                if(temp > y) {
                    r = m;
                } else {
                    l = m;
                }
            }
            cout << fixed << setprecision(4) << l << endl;
        }
    }
    return 0;
}