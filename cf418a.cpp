#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];
vector<int> vacant_pos;
int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0)
            vacant_pos.push_back(i);
    }
    for(int i = 0; i < m; i++) { cin >> b[i]; }
    sort(b, b + m);
    reverse(b, b + m);
    for(int i = 0; i < (int)vacant_pos.size(); i++){
        int p = vacant_pos[i];
        a[p] = b[i];
    }
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(a[i - 1] > a[i]){
            flag = true;
            break;
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
