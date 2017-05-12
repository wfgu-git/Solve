#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
string s;
vector<int> End;
int check(int len) {
    int n = End.size();
    int cnt = 0;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (len < End[i]) return inf;
        if (temp + End[i] <= len) temp += End[i];
        else ++cnt, temp = End[i];
    }
    return ++cnt;
}

int main(int argc, char const *argv[]) {
    int k;
    cin >> k;
    cin.get();
    getline(cin, s);
    int strsz = s.size();
    for (int i = 0; i < strsz; i++) {
        if (s[i] == ' ' || s[i] == '-')
            End.push_back(i);
    }
    for (int i = End.size() - 1; i >= 1; i--) End[i] -= End[i - 1];
    End[0] += 1;

    int l = 0, r = strsz;
    while (l < r) {
        int mid = l + (r - l) / 2;
        cout << l << "  " << r << "   ";
        cout << "len = " << check(mid) << endl;
        if (check(mid) >= k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << r << endl;
    return 0;
}



