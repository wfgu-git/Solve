#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int a[105];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]) cnt++;
    }
    int val = -inf;
    for(int s = 0; s < n; s++) {
        for(int e = s; e < n; e++) {
            int cntOne = 0;
            int cntZero = 0;
            for(int i = s; i <= e; i++) {
                if(a[i])  cntOne++;
                else cntZero++;
            }
            val = max(val, cntZero - cntOne);
        }
    }
    cout << val + cnt << endl;
    return 0;
}