#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int main()
{
    ios::sync_with_stdio(false);
    string ori;
    cin >> ori;
    int n = (int)ori.size();
    for (auto ch : ori) {
        cnt[ch - 'a']++;
    }
    int odd_char = 0;
    for (auto cont : cnt) {
        if (cont & 1)
            odd_char++;
    }
    if (n & 1) {
        if (odd_char != 1) {
            for (int i = 25; i >= 0; i--) {
                if (odd_char > 1 && cnt[i] & 1) {
                    for (int j = 0; j < i; j++) {
                        if (cnt[j] & 1) {
                            cnt[i]--, cnt[j]++;
                            odd_char--;
                            break;
                        }
                    }
                }
            }
        }
        string ans = "";
        char mid;
        for (int i = 0; i < 26; i++) if(cnt[i] & 1) { mid = 'a' + i; cnt[i]--;}
        for (int i = 0; i < 26; i++) cnt[i] >>= 1;
        for (int i = 0; i < 26; i++) {
            while (cnt[i]--) {
                ans.push_back('a' + i);
            }
        }
        string ans_end(ans.rbegin(), ans.rend());
        ans.push_back(mid);
        ans += ans_end;
        cout << ans;
    } else {
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] & 1) {
                for (int j = 0; j < i; j++){
                    if (cnt[j] & 1) {
                        cnt[j]++, cnt[i]--;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++) cnt[i] >>= 1;
        string ans = "";
        for (int i = 0; i < 26; i++) {
            while (cnt[i]--) {
                ans.push_back('a' + i);
            }
        }
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}

