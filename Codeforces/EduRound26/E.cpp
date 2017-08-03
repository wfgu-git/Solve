#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
ll f(ll v)
{
  if (v == 0)
  {
    return 0;
  }
  ll g = __gcd(a, v);
  ll x = a / g;
  ll y = v / g;
  vector<ll> ps;
  vector<ll> rems;
  for (ll i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      ps.push_back(i);
      while(x % i == 0)
      {
        x /= i;
      }
    }
  }
  if (x != 1)
  {
    ps.push_back(x);
  }
  for (int i= 0; i < ps.size(); i++)
  {
    rems.push_back(y % ps[i]);
  }
  ll u = rems.empty()? y: *min_element(rems.begin(), rems.end());
  return f((y - u) * g) + u;
}
int main()
{
  while(cin >> a >> b)
  {
    cout << f(b) << endl;
  }
}
