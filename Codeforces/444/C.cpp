/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

int raw[25], temp[25];
bool check(int k) {
  memcpy(temp, raw, sizeof(raw));
  switch (k) {
    case 0: {
      temp[6] = raw[2];
      temp[8] = raw[4];
      temp[10] = raw[6];
      temp[12] = raw[8];
      temp[23] = raw[10];
      temp[21] = raw[12];
      temp[2] = raw[23];
      temp[4] = raw[21];
      int cont = 0;
      for (int i = 0; i < 6; ++i) {
        set<int> S = {temp + i * 4 + 1, temp + i * 4 + 1 + 4};
        cont += (S.size() == 1);
      }
      if (cont == 6) return 1;
    } break;
    case 1: {
      temp[6] = raw[10];
      temp[8] = raw[12];
      temp[10] = raw[23];
      temp[12] = raw[21];
      temp[21] = raw[4];
      temp[23] = raw[2];
      temp[2] = raw[6];
      temp[4] = raw[8];
      int cont = 0;
      for (int i = 0; i < 6; ++i) {
        set<int> S = {temp + i * 4 + 1, temp + i * 4 + 1 + 4};
        cont += (S.size() == 1);
      }
      if (cont == 6) return 1;
    } break;
    case 2: {
      temp[1] = raw[18];
      temp[2] = raw[20];
      temp[18] = raw[12];
      temp[20] = raw[11];
      temp[11] = raw[13];
      temp[12] = raw[15];
      temp[13] = raw[2];
      temp[15] = raw[1];
      int cont = 0;
      for (int i = 0; i < 6; ++i) {
        set<int> S = {temp + i * 4 + 1, temp + i * 4 + 1 + 4};
        cont += (S.size() == 1);
      }
      if (cont == 6) return 1;
    } break;
    case 3: {
      temp[1] = raw[15];
      temp[2] = raw[13];
      temp[13] = raw[11];
      temp[15] = raw[12];
      temp[11] = raw[20];
      temp[12] = raw[18];
      temp[20] = raw[2];
      temp[18] = raw[1];
      int cont = 0;
      for (int i = 0; i < 6; ++i) {
        set<int> S = {temp + i * 4 + 1, temp + i * 4 + 1 + 4};
        cont += (S.size() == 1);
      }
      if (cont == 6) return 1;
    } break;
    case 4: {
      temp[24] = raw[20];
      temp[23] = raw[19];
      temp[20] = raw[7];
      temp[19] = raw[8];
      temp[7] = raw[16];
      temp[8] = raw[15];
      temp[15] = raw[23];
      temp[16] = raw[14];
      int cont = 0;
      for (int i = 0; i < 6; ++i) {
        set<int> S = {temp + i * 4 + 1, temp + i * 4 + 1 + 4};
        cont += (S.size() == 1);
      }
      if (cont == 6) return 1;
    } break;
    case 5: {
      temp[24] = raw[16];
      temp[23] = raw[15];
      temp[15] = raw[8];
      temp[16] = raw[7];
      temp[8] = raw[19];
      temp[7] = raw[20];
      temp[20] = raw[24];
      temp[19] = raw[23];
      int cont = 0;
      for (int i = 0; i < 6; ++i) {
        set<int> S = {temp + i * 4 + 1, temp + i * 4 + 1 + 4};
        cont += (S.size() == 1);
      }
      if (cont == 6) return 1;
    } break;
    default: break;
  }
  return 0;
}
void work() {
  for (int i = 1; i <= 24; ++i) {
    cin >> raw[i];
  }

  for (int i = 0; i  < 6; ++i) {
    if (check(i)) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  // freopen("data.in", "r", stdin);
  work();
}
