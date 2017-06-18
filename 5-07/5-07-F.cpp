#include <iostream>
using namespace std;

int cntZero(int x) {
    int ret = 0;
    int p = 5;
    while (x / p) {
        ret += x / p;
        p *= 5;
    }
    return ret;
}
int main(void) {
    int n;
    while (cin >> n) {
        cout << cntZero(n) << endl;
    }
    return 0;
}
