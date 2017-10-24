int fail[maxn];
void get_fail(const string& t) {
  fail[0] = -1;
  int n = t.size();
  int j = 0;
  int k = -1;
  while (j < n) {
    if (k == -1 || t[j] == t[k]) {
      fail[++j] = ++k;
    } else {
      k = fail[k];
    }
  }
}
int KMP(const string& s, const string& t) {
  get_fail(t);
  int sn = s.size();
  int tn = t.size();
  int i = 0;
  int j = 0;
  while (i < sn && j < tn) {
    if (j == -1 || s[i] == t[j]) {
      ++i; ++j;
    } else {
      j = fail[j];
    }
  }
  if (j == tn) return i - tn + 1;
  else return -1;
}
