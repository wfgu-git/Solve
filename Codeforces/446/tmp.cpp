#include<bits/stdc++.h>

using namespace std;

int a[2050];

int gcd(int a, int b)

{

 return b ? gcd(b, a%b) : a;

}

int main()

{

 int n;

 cin >> n;

 cin >> a[1];

 int totgcd = a[1];

 int cnt1 = 0;

 if (a[1] == 1)

  cnt1++;

 int flag = 0;

 for (int i = 2; i <= n; i++)

 {

  cin >> a[i];

  if (a[i] == 1)

   cnt1++;

  totgcd = gcd(totgcd, a[i]);

 }

 if (totgcd != 1)

  cout << -1 << endl;

 else

 {

  int minn = 1000000;

  for (int i = 1; i <= n; i++)

   for (int j = i + 1; j <= n; j++)

    if (gcd(a[i], a[j]) == 1)

     minn = min(minn, j - i);

  cout << minn + n - cnt1 - 1 << endl;

 }

}
