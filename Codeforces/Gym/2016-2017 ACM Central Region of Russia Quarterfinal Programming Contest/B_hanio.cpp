#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
long long ans;
string steps;
int cut[3];
bool flag;
string add(string str1, string str2) {
  int len1 = str1.size();
  int len2 = str2.size();
  if (len1 < len2) {
    swap(str1, str2);
    swap(len1, len2);
  }
  int c = 0;
  for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--) {
    int temp = 0;
    if (j >= 0) temp += str2[j] - '0';
    temp += str1[i] + c - '0';
    str1[i] = temp % 10 + '0';
    c = temp / 10;
  }
  if (c) str1 = '1' + str1;
  return str1;
}
void judge() {
  if (cut[0] == cut[1] && cut[1] == cut[2]) {
    cout << steps << endl;
    flag = 0;
  }
}
int move(int x, char a, char b) {
  cut[a - 'A']--;
  cut[b - 'A']++;
  steps = add(steps, "1");
  judge();
  // for(int i=0;i<3;i++)
  // cout<<cut[i]<<endl;
  // printf("number..%d..form..%c..to..%c\n",x,a,b);
}

int mission(int x, char a, char b, char c) {
  if (!flag) return 0;
  if (x == 1)
    move(1, a, c);
  else {
    mission(x - 1, a, c, b);  //将x-1从a借c移到b。
    move(x, a, c);
    mission(x - 1, b, a, c);  //将x-1从b借a移到c。
  }
  return 0;
}
int main() {
  int n;
  for (int i = 1; i <= 100; i++) {
    n = i * 3;
    flag = 1;
    steps = "0";
    cut[0] = n;
    cut[1] = cut[2] = 0;
    mission(n, 'A', 'B', 'C');
  }
  return 0;
}
