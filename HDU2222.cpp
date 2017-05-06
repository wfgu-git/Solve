// training for AC automation
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000;
const int charKind = 26;
struct Trie {
    int next[maxn][charKind], fail[maxn], end[maxn];
    int root, L;
    int newNode() {
        for (int i = 0; i < charKind; i++) next[L][i] = -1;
        end[L] = 0;
        return L++;
    }
    void init() {
        L = 0;
        root = newNode();
    }
    void insert(char *buf) {
        int cur = root;
        while (*buf != '\0') {
            if (next[cur][*buf - 'a'] == -1) next[cur][*buf - 'a'] = newNode();
            cur = next[cur][*buf - 'a'];
        }
        end[cur]++;
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < charKind; i++) {
            if (next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < charKind; i++) {
                if (next[cur][i] == -1) {
                    next[cur][i] = next[fail[cur]][i];
                } else {
                    fail[next[cur][i]] = next[fail[cur]][i];
                    q.push(next[cur][i]);
                }
            }
        }
    }
    int solve(char *s) {
        int ret = 0, k = 0;
        while (*s != '\0') {
            int t = *s - 'a';
            k = next[k][t];
            int j = k;
            while (j) {
                ret += end[j];
                end[j] = 0;
                j = fail[j];
            }
            s++;
        }
        return ret;
    }
};

char buf[1000005];
Trie ac;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ac.init();
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("%d\n", ac.solve(buf));
    }
    return 0;
}
