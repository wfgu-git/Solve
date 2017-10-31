typedef complex<double> Complex;
const long double PI = acos(0.0) * 2.0;
void FFT(vector<Complex> &a, bool inverse) {
  int n = a.size();
  for(int i = 0, j = 0; i < n; i++) {
    if(j > i) swap(a[i], a[j]);
    int k = n;
    while(j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  double pi = inverse ? -PI : PI;
  for(int step = 1; step < n; step <<= 1) {
    double alpha = pi / step;
    for(int k = 0; k < step; k++) {
      Complex omegak = exp(Complex(0, alpha*k));
      for(int Ek = k; Ek < n; Ek += step << 1) {
        int Ok = Ek + step;
        Complex t = omegak * a[Ok];
        a[Ok] = a[Ek] - t;
        a[Ek] += t;
      }
    }
  }

  if(inverse)
    for(int i = 0; i < n; i++) a[i] /= n;
}
vector<int> operator * (const vector<double>& v1, const vector<double>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while(S < s1 + s2) S <<= 1;
  vector<Complex> a(S,0), b(S,0);
  for(int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for(int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for(int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<int> res(S + 1);
  for (int i = 0; i < S; ++i) {
    res[i] = a[i].real() + 0.5;
  }
  for (int i = 0; i < S; ++i) {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
  return res;
}
struct bign {
  int len, s[2020];
  bign() {
    memset(s, 0, sizeof(s));
    len = 1;
  }
  bign(int num) { *this = num; }
  bign(const char *num) { *this = num; }
  bign operator=(const int num) {
    char s[2020];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }
  bign operator=(const char *num) {
    for (int i = 0; num[i] == '0'; num++) ;
    len = strlen(num);
    for (int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
    return *this;
  }
  bign operator+(const bign &b) const  //+
  {
    bign c;
    c.len = 0;
    for (int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if (i < len) x += s[i];
      if (i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      g = x / 10;
    }
    return c;
  }
  bign operator+=(const bign &b) {
    *this = *this + b;
    return *this;
  }
  void clean() {
    while (len > 1 && !s[len - 1]) len--;
  }
  bign operator*(const bign &b)  //*
  {
    bign c;
    vector<double> ta, tb;
    for (int i = 0; i < len; ++i) {
      ta.push_back((double)s[i]);
    }
    for (int i = 0; i < b.len; ++i) {
      tb.push_back((double)b.s[i]);
    }
    vector<int> tmp = ta * tb;
    for (int i = 0; i < tmp.size(); ++i) {
      c.s[i] = tmp[i];
    }
    c.len = tmp.size();
    c.clean();
    return c;
  }
  bign operator*=(const bign &b) {
    *this = *this * b;
    return *this;
  }
  bign operator-(const bign &b) {
    bign c;
    c.len = 0;
    for (int i = 0, g = 0; i < len; i++) {
      int x = s[i] - g;
      if (i < b.len) x -= b.s[i];
      if (x >= 0)
        g = 0;
      else {
        g = 1;
        x += 10;
      }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
  }
  bign operator-=(const bign &b) {
    *this = *this - b;
    return *this;
  }
  bign operator/(const bign &b) {
    bign c, f = 0;
    for (int i = len - 1; i >= 0; i--) {
      f = f * 10;
      f.s[0] = s[i];
      while (f >= b) {
        f -= b;
        c.s[i]++;
      }
    }
    c.len = len;
    c.clean();
    return c;
  }
  bign operator/=(const bign &b) {
    *this = *this / b;
    return *this;
  }
  bign operator%(const bign &b) {
    bign r = *this / b;
    r = *this - r * b;
    return r;
  }
  bign operator%=(const bign &b) {
    *this = *this % b;
    return *this;
  }
  bool operator<(const bign &b) {
    if (len != b.len) return len < b.len;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] != b.s[i]) return s[i] < b.s[i];
    }
    return false;
  }
  bool operator>(const bign &b) {
    if (len != b.len) return len > b.len;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] != b.s[i]) return s[i] > b.s[i];
    }
    return false;
  }
  bool operator==(const bign &b) { return !(*this > b) && !(*this < b); }
  bool operator!=(const bign &b) { return !(*this == b); }
  bool operator<=(const bign &b) { return *this < b || *this == b; }
  bool operator>=(const bign &b) { return *this > b || *this == b; }
  string str() const {
    string res = "";
    for (int i = 0; i < len; ++i) res.push_back(s[i] + '0');
    reverse(res.begin(), res.end());
    return res;
  }
};
istream &operator>>(istream &in, bign &x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream &operator<<(ostream &out, const bign &x) {
  out << x.str();
  return out;
}
