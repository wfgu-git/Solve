#include <bits/stdc++.h>
using namespace std;

int n, a[1005], b[1005], ans[1005];
vector<int> p;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) { cin >> a[i]; }
    for(int i = 0; i < n; i++) { cin >> b[i]; }

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            p.push_back(i);
            cnt++;
            continue;
        }
        ans[i] = a[i];
        s.erase(a[i]);
    }

    if(cnt == 1){
        auto it = s.begin();
        ans[p[0]] = *it;
    } else {
        int pa = p[0];
        int pb = p[1];
        auto it = s.begin();
        int aa = *it++;
        int bb = *it;
        //cout << aa << " " << bb << endl;
        if( (a[pa] != aa && a[pb] != bb) || b[pa] != aa && b[pb]!= bb){
            swap(aa, bb);
        }
        ans[pa] = aa;
        ans[pb] = bb;
    }
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    return 0;
}
