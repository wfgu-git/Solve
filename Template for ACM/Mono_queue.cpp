for (int i = 0; i < n; i++) l[i] = r[i] = i;
for (int i = 1; i < n; i++) {
  int now = i;
  while (now >= 1 && a[i] <= a[now - 1]) now = l[now - 1];
  l[i] = now;
}
for (int i = n - 2; i >= 0; i--) {
  int now = i;
  while (now < n - 1 && a[i] <= a[now + 1]) now = r[now + 1];
  r[i] = now;
}
