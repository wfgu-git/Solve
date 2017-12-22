typedef long long ll;
const int TEN[] = {1,      10,      100,      1000,     10000,
                   100000, 1000000, 10000000, 100000000};
const int MV = 100000000;
struct BigInt {
  vector<int> a;
  void Handle() {
    int n = (int)a.size();
    while (n && a[n - 1] == 0) n--;
    a.resize(n);
  }
  BigInt() {}
  BigInt(ll x) {
    while (x) {
      a.push_back(x % MV);
      x /= MV;
    }
  }
  BigInt(const string &s) {
    int slen = s.length();
    for (int i = slen - 1; i >= 0; i -= 8) {
      int x = 0;
      for (int j = 0; j < 8; j++) {
        if (i >= j)
          x += TEN[j] * (s[i - j] - '0');
        else
          break;
      }
      a.push_back(x);
    }
    Handle();
  }
  BigInt(char *s) {
    int slen = strlen(s);
    for (int i = slen - 1; i >= 0; i -= 8) {
      int x = 0;
      for (int j = 0; j < 8; j++) {
        if (i >= j) x += TEN[j] * (s[i - j] - '0');
      }
      a.push_back(x);
    }
    Handle();
  }
  // x < y返回负数, x == y返回0, x > y返回正数
  friend int Cmp(const BigInt &x, const BigInt &y) {
    if (x.a.size() == y.a.size()) {
      for (int i = (int)x.a.size() - 1; i >= 0; i--) {
        if (x.a[i] != y.a[i]) return x.a[i] - y.a[i];
      }
      return 0;
    } else {
      return (int)x.a.size() - (int)y.a.size();
    }
  }
  friend BigInt operator+(const BigInt &x, const BigInt &y) {
    BigInt r;
    int xs = x.a.size(), ys = y.a.size(), sp = 0;
    for (int i = 0; i < xs || i < ys; i++) {
      int u;
      if (i >= xs)
        u = y.a[i] + sp;
      else if (i >= ys)
        u = x.a[i] + sp;
      else
        u = x.a[i] + y.a[i] + sp;
      if (u >= MV) {
        r.a.push_back(u - MV);
        sp = 1;
      } else {
        r.a.push_back(u);
        sp = 0;
      }
    }
    r.a.push_back(sp);
    r.Handle();
    return r;
  }
  friend BigInt operator-(const BigInt &x, const BigInt &y) {
    BigInt r;
    int cmp = Cmp(x, y), u, sp = 0;
    int xs = x.a.size(), ys = y.a.size();
    if (cmp == 0) {
      return r;
    } else if (cmp > 0) {
      for (int i = 0; i < xs; i++) {
        if (i >= ys)
          u = x.a[i] + sp;
        else
          u = x.a[i] - y.a[i] + sp;
        if (u < 0) {
          u += MV;
          sp = -1;
        } else {
          sp = 0;
        }
        r.a.push_back(u);
      }
    } else {
      for (int i = 0; i < ys; i++) {
        if (i >= xs)
          u = y.a[i] + sp;
        else
          u = y.a[i] - x.a[i] + sp;
        if (u < 0) {
          u += MV;
          sp = -1;
        } else {
          sp = 0;
        }
        r.a.push_back(u);
      }
    }
    r.Handle();
    return r;
  }
  // O(n * m)普通乘法
  friend BigInt operator*(const BigInt &x, const BigInt &y) {
    int xs = (int)x.a.size(), ys = (int)y.a.size(), tot = xs + ys;
    BigInt r;
    vector<ll> v(xs + ys, 0LL);
    for (int i = 0; i < xs; i++) {
      for (int j = 0; j < ys; j++) {
        v[i + j] += (ll)x.a[i] * (ll)y.a[j];
        v[i + j + 1] += v[i + j] / MV;
        v[i + j] %= MV;
      }
    }
    for (int i = 0; i < tot; i++) r.a.push_back((int)v[i]);
    r.Handle();
    return r;
  }
  friend BigInt operator/(const BigInt &x, int y) {
    BigInt r;
    ll u = 0;
    for (int i = (int)x.a.size() - 1; i >= 0; i--) {
      u = u * MV + x.a[i];
      r.a.push_back((int)(u / y));
      u %= y;
    }
    reverse(r.a.begin(), r.a.end());
    r.Handle();
    return r;
  }
  friend int operator%(const BigInt &x, int y) {
    ll u = 0;
    for (int i = (int)x.a.size() - 1; i >= 0; i--) {
      u = u * MV + x.a[i];
      u %= y;
    }
    return u;
  }
  friend istream &operator>>(istream &in, BigInt &x) {
    string s;
    cin >> s;
    x = BigInt(s);
    return in;
  }
  friend ostream &operator<<(ostream &out, const BigInt &x) {
    int n = (int)x.a.size() - 1;
    if (n < 0) {
      out << 0;
    } else {
      out << x.a[n--];
      while (n >= 0) out << setfill('0') << setw(8) << x.a[n--];
    }
    return out;
  }
};
