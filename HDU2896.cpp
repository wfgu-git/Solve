#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000000;
const int chsize = 100;
struct trie {
    int fail[maxn], next[maxn][chsize], end[maxn];
    int root, L, id;
    int newnode() {
        id = -1;
        for (int i = 0; i < chsize; i++) next[L][i] = -1;
        end[L] = 0;
        return L++;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(char *s) {
        int cur = root, ch;
        while (*s) {
            ch = *s - ' ';
            if (next[cur][ch] == -1) next[cur][ch] = newnode();
            cur = next[cur][ch];
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
        int ans = 0, temp;
        while (*s) {
            int ch = *s - ' ';
            temp = next[temp][ch];
            int j = temp;
            while (j) {
                ans += end[j];
                end[j] = 0;
                j = fail[j];
            }
            s++;
        }
        return ans;
    }
};

trie ac;
char buf[10010];
int n, q;
int main(void) {
    while (scanf("%d", &n) == 1) {
        ac.init();
        for (int i = 1; i <= n; i++) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        scanf("%d", &q);
        for (int i = 1; i <= q; i++) {
            scanf("%s", buf);
            printf("web %d:", i);
            printf(" %d", ac.solve(buf));
            printf("\n");
        }
    }
    return 0;
}
