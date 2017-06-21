#include <bits/stdc++.h>
using namespace std;

priority_queue < int, vector <int>, greater < int > > q;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            q.push(x);
        }

        while (q.size() >= 2) {
            int x1 = q.top();
            q.pop();
            int x2 = q.top();
            q.pop();
            q.push(x1 + x2);
        }
        printf("%d\n", q.top());
    }
    return 0;
}