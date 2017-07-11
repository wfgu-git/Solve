#include <bits/stdc++.h>
using namespace std;
const int maxn = 500500;
const int chsize = 26;
char buf[1000500];
struct trie {
    int cnt;
    int fail[maxn], next[maxn][chsize], end[maxn];
    int root, L;
    int newnode() {
        for (int i = 0; i < chsize; i++) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(char *s) {
        int cur = root;
        while (*s) {
            int id = *s - 'a';
            if (next[cur][id] == -1) next[cur][id] = newnode();
            cur = next[cur][id];
            s++;
        }
        end[cur]++;
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < chsize; i++) {
            if (next[root][i] == -1)
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < chsize; i++) {
                if (next[cur][i] == -1)
                    next[cur][i] = next[fail[cur]][i];
                else {
                    fail[next[cur][i]] = next[fail[cur]][i];
                    q.push(next[cur][i]);
                }
            }
        }
    }
    int solve(char *s) {
        int ret = 0, k = 0;
        while (*s) {
            int id = *s - 'a';
            k = next[k][id];
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
trie ac;
int main(void) {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
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
