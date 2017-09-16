#include <bits/stdc++.h>
using namespace std;
map < string, int > ans;
const int dx[] = {1, -1, 4, -4};
void bfs() {
    queue < string > q;
    string ori = "01234567";
    ans.clear();
    ans[ori] = 0;
    q.push(ori);

    while (!q.empty()) {
        string now = q.front();
        q.pop();

        int x;
        for (int i = 0; i < 8; i++) {
            if (now[i] == '0') {
                x = i;
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            if (tx < 0 || tx >= 8) continue;
            if (x == 3 && i == 0) continue;
            if (x == 4 && i == 1) continue;

            string tstr = now;
            swap(tstr[tx], tstr[x]);
            if (!ans.count(tstr)) {
                ans[tstr] = ans[now] + 1;
                q.push(tstr);
            }
        }
    }
}
int main() {

    bfs();
    string line;
    while (getline(cin, line)) {
        auto sz = remove(line.begin(), line.end(), ' ');
        line.erase(sz, line.end());
        cout << ans[line] << endl;
    }
    return 0;
}

