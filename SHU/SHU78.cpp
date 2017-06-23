#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
struct Info {
    int cnt5, cnt10, cnt20;
    int money;

    int all() const {
        return cnt5 * 5 + cnt10 * 10 + cnt20 * 20;
    }
    Info() {}
    Info(int _cnt5, int _cnt10, int _cnt20)
    : cnt5(_cnt5), cnt10(_cnt10), cnt20(_cnt20) {
        money = all();
    }
}info[maxn + 5];

int twenty, ten, five;
bool solve(const int &n)
{
    for (int i = 0; i < n; i++) {
        while (twenty && info[i].money >= 20) twenty--, info[i].money -= 20;
        while (ten && info[i].money >= 10) ten--, info[i].money -= 10;
        while (five && info[i].money >= 5) five--, info[i].money -= 5;
    }

    if (n * 15 == twenty * 20 + ten * 10 + five * 5)
        return true;
    else
        return false;
}
int main()
{
    int n;
    while (cin >> n) {
        five = 0;
        ten = 0;
        twenty = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            five += a;
            ten += b;
            twenty += c;
            info[i] = Info(a, b, c);
            if (info[i].money - 15 < 0)
                flag = false;
            info[i].money -= 15;
        }
        if (!flag) {
            cout << "Angry Yaoge!" << endl;
        } else {
            if (solve(n))
                cout << "Happy Yaoge!" << endl;
            else
                cout << "Sad Yaoge!" << endl;
        }
    }
    return 0;
}

