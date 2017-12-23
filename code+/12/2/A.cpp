/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

int cont[100][2];
void work() {
  int n, m;
  cin >> n >> m;
  for (int p = 0; p < n; ++p) {
    memset(cont, 0, sizeof(cont));
    string str;
    cin >> str;

    int l = str.size();
    if (str[l - 1] >= 'A' && str[l - 1] <= 'Z') {
      str.push_back('1');
    }
    int f = 1;
    while (f) {
      f = 0;
      l = str.size();
      for (int i = 0; i < l; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          if (i + 1 < l && !(str[i + 1] >= '0' && str[i + 1] <= '9')) {
            f = 1;
            str.insert(i + 1, "1");
          }
        }
      }
    }
    // cout << " ### " << str << endl;

    int idx = (int)str.find("=");
    int flag = 0;
    for (int i = 0; i < idx; ++i) {
      if (str[i] == '?') {
        flag = -1;
        continue;
      }
      if (str[i] >= 'A' && str[i] <= 'Z') {
        if (i + 1 < idx && str[i + 1] >= '0' && str[i + 1] <= '9') {
          cont[str[i] - 'A'][0] += str[i + 1] - '0';
        }
      }
    }
    for (int i = idx + 1; i < l; ++i) {
      if (str[i] == '?') {
        flag = 1;
        continue;
      }
      if (str[i] >= 'A' && str[i] <= 'Z') {
        if (i + 1 < l && str[i + 1] >= '0' && str[i + 1] <= '9') {
          cont[str[i] - 'A'][1] += str[i + 1] - '0';
        }
      }
    }

    string ans;
    int non = 0;
    if (flag < 0) {
      // cout << " = is right!!!" << endl;
      for (char i = 'A'; i <= 'Z'; ++i) {
        int num = cont[i - 'A'][1] - cont[i - 'A'][0];
        // cout << i << "  num = " << num << endl;
        if (num == 0) {
          continue;
        }
        if (num < 0 || num > 9) {
          non = 1;
          break;
        }
        ans.push_back(i);
        if (num >= 2 && num <= 9) {
          ans.push_back('0' + num);
        }
      }
    } else {
      for (char i = 'A'; i <= 'Z'; ++i) {
        int num = cont[i - 'A'][0] - cont[i - 'A'][1];
        if (num == 0) {
          continue;
        }
        if (num < 0 || num > 9) {
          non = 1;
          break;
        }
        ans.push_back(i);
        if (num >= 2 && num <= 9) {
          ans.push_back('0' + num);
        }
      }
    }
    if (non || !ans.size()) {
      cout << "No Solution\n";
      continue;
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
