#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll pow_mod(ll x, ll n)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
ll Cm(ll n, ll m)
{
	ll a = 1, b = 1;
	if (m > n) return 0;
	while (m)
	{
		a = (a * n--) % mod;
		b = (b * m--) % mod;
	}
	return (a * pow_mod(b, mod - 2)) % mod;
}
ll Lucas(ll n, ll m)
{
	if (m == 0)
		return 1;
	return (Cm(n % mod, m % mod) * Lucas(n / mod, m / mod)) % mod;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n, m;
		scanf("%I64d%I64d", &n, &m);
		long long b = max(n, m), s = min(n, m);

		cout << Cm(b, s) << endl;
	}
}
