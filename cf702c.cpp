#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> tower, city;
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        city.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        tower.push_back(x);
    }
    int r;
    int ret = -1;
    for(int x : city){
        auto a = lower_bound(tower.begin(), tower.end(), x);
        if(a == tower.end()) a--;
        auto b = a;
        if(a != tower.begin()) b = a - 1;
        //cout << "to city no. " << x << "  " << *a << "  " << *b << endl;
        r = min(abs(*a - x), abs(*b - x));
        ret = max(ret, r);
    }
    cout << ret << endl;
    return 0;
}
