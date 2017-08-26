#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string all;
    getline(cin, all);
    all.erase(remove(all.begin(), all.end(), ' '), all.end());
    int length = all.size();
    int cut = length / 2;
    int permute = 1 << length;
    int result = 0x3F3F3F3F;
    do {
      bitset<10> used = static_cast<bitset<10>>(permute);
      string s1, s2;
      for (int i = 0; i < length; ++i) {
        if (used[i]) {
          s1 += all[i];
        } else {
          s2 += all[i];
        }
      }
      if (s1.size() != cut) {
        continue;
      }
      if (s1[0] == '0' && s1.size() > 1) {
        continue;
      }
      // s1 s2 已经被切割出来了
      // 穷举它们
      do {
        int n1 = atoi(s1.c_str());
        do {
          if (s2[0] == '0' && s2.size() > 1) {
            continue;
          }
          int n2 = atoi(s2.c_str());
          int dif = abs(n1 - n2);
          // cout << s1 << ' ' << s2 << " dif " << dif << " result: " << result
          // << endl;
          if (dif < result) {
            result = dif;
          }
        } while (next_permutation(s2.begin(), s2.end()));
      } while (next_permutation(s1.begin(), s1.end()));
    } while (--permute);

    cout << result << endl;
  }
#ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  system("out.txt");
#endif
  return 0;
}
///////////////////////////End Sub//////////////////////////////////
