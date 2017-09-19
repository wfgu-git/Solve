void Suffix() {
  static int set[maxn + 1], a[maxn + 1];
  copy(s  + 1, s + n + 1, set + 1);
  sort(set + 1, set + n + 1);
  int *end = unique(set + 1, set + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(set + 1, end, s[i]) - set;
  }

  static int fir[maxn + 1], sec[maxn + 1], tmp[maxn + 1], buc[maxn + 1];
  for (int i = 1; i <= n; ++i) buc[a[i]]++;
  for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
  for (int i = 1; i <= n; ++i) rk[i] = buc[a[i] - 1] + 1;

  for (int t = 1; t <= n; t *= 2) {
    for (int i = 1; i <= n; ++i) fir[i] = rk[i];
    for (int i = 1; i <= n; ++i) sec[i] = (i + t > n ? 0 : rk[i + t]);

    fill(buc, buc + n + 1, 0);
    for (int i = 1; i <= n; ++i) buc[sec[i]]++;
    for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
    for (int i = 1; i <= n; ++i) tmp[n - --buc[sec[i]]] = i;

    fill(buc, buc + n + 1, 0);
    for (int i = 1; i <= n; ++i) buc[fir[i]]++;
    for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
    for (int j = 1, i; j <= n; ++j) {
      i = tmp[j];
      sa[buc[fir[i]]--] = i;
    }
  }
}
