#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};

bool cmpr(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;

}

multiset<pair<int, int>, cmp> s;
vector<pair<int, int> > vp;
map<int, pair<int, int> > rk;
int main(void) {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int p, t;
        cin >> p >> t;
        // s.insert({p, t});
        vp.push_back({p, t});
    }
    sort(vp.begin(), vp.end(), cmpr);
    k = k - 1;
    pair<int, int> need = vp[k];
    int cnt = 0;
    for(auto &p : vp) {
        if(p == need) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
