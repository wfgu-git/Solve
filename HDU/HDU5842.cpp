// #include <bits/stdc++.h>
// using namespace std;
//
// char a[100005];
// int d[100005];
// int main(void) {
//     int kase;
//     scanf("%d", &kase);
//     for (int t = 1; t <= kase; t++) {
//         //memset(d, 0, sizeof(d));
//         scanf("%s", a);
//         int n = strlen(a);
//         int len = 1;
//         d[1] = a[0] - 'a';
//         for (int i = 1; i < n; i++) {
//             if (a[i] - 'a' > d[len]) {
//                 d[++len] = a[i] - 'a';
//             } else {
//                 int p = lower_bound(d + 1, d + 1 + len, a[i] - 'a') - d;
//                 d[p] = a[i] - 'a';
//             }
//         }
//         printf("Case #%d: %d\n", t, len);
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[35];
int main(void) {
    ios::sync_with_stdio(false);
    int kase;
    cin >> kase;
    for (int t = 1; t <= kase; t++) {
        cin >> s;
        int n = s.size();
        memset(cnt, 0, sizeof(cnt));
        int ret = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 1) ret++;
        }
        cout << "Case #" << t << ": " << ret << endl;
    }
    return 0;
}
