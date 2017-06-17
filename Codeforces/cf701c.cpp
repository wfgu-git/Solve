#include <bits/stdc++.h>
using namespace std;

map<char, int> cnt;
set<char> kind;
string s;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n >> s;
    for(int i = 0; i < n; i++) kind.insert(s[i]);
    int tot = kind.size();

    int ret = 10000000;
    int l = 0, r = 0;
    while(r < n) {
        cnt[s[r]]++;
        while(l < n && cnt.size() == tot) {
            ret = min(ret, r - l + 1);
            cnt[s[l]]--;
            if(cnt[s[l]] == 0) {
                cnt.erase(s[l]);
            }
            l++;
        }
        r++;
    }
    cout << ret << endl;
    return 0;
}