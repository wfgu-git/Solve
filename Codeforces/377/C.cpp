#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
    ll b, d, s;
    cin >> b >> d >> s;
    ll days = max(b, max(d, s));
    ll avg = days - 1;
    cout << max(0ll, avg- b) + max(0ll, avg - d) +
                max(0ll, avg - s)
         << endl;

    return 0;
}
