#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll pow_mod(ll x, ll n) {
    const ll moder = n;
    ll base = x, ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * base % moder;
        base = base * base % moder;
        n >>= 1;
    }
    return ans;
}
bool is_prime(int x) {
    if (x == 2) return true;
    bool flag = true;
    int m = (int)(sqrt(1.0 * x)) + 1;
    for (int i = 2; i <= m; i++) {
        if (x % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    int a, p;
    while (cin >> p >> a) {
        if (!(a + p)) break;
        if (!is_prime(p) && a % p == pow_mod(a, p) % p) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
