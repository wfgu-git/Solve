#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n,m;
int pre[maxn],d[maxn];
bool vis[maxn];

bool check(int x) {
    memset(vis, 0, sizeof(vis));
    int cur = x - 1;
    for(int i = x; i>=1; i--){
        cur = min(cur, i-1);
        if(d[i] && !vis[d[i]] && pre[d[i]] <= cur){
            vis[d[i]] = true;
            cur -= pre[d[i]] + 1;
        }
    }
    for(int i=1;i<=m;i++){
        if(!vis[i])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) cin >> pre[i];

    int l = m, r= n,ret = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)){
            r = mid - 1;
            ret = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << ret << endl;
    return 0;
}
