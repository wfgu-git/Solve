int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(int *a, int n) {
  int x = 0;
  for (int i = 0; i < n; ++i) {
    int cont = 1;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[i]) {
        ++cont;
      }
    }
    x += cont * fact[n - i - 1];
  }
  return x;
}

void decantor(int x, int n) {
  n--;
  vector<int> ret, unused;
  for (int i = 1; i <= m; i++) unused.push_back(i);
  for (int i = m; i >= 1; i--) {
    ll r = n % fact[i - 1];
    ll t = n / fact[i - 1];
    n = r;
    sort(unused.begin(), unused.end());
    ret.push_back(unused[t]);
    unused.erase(unused.begin() + t);
  }
}
