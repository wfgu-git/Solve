#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<string>
#include<cstring>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#define sf(a) scanf("%lf",&a)
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf(a) scanf("%lf",&a)
#define sf2(a,b) scanf("%lf%lf",&a,&b)
#define mp(a,b) make_pair(a,b)
#define maxn 200005
using namespace std;
typedef long long ll;
vector<int>vec,w,all;
map<int,int>ma;
int c[maxn];
int dp[maxn];
void update(int pos, int x){
    while(pos < maxn){
        c[pos] = max(x, c[pos]);
        pos += pos&(-pos);
    }
}
int qry(int pos){
    int ans = 0;
    while(pos > 0){
        ans = max(ans,c[pos]);
        pos -= pos&(-pos);
    }
    return ans;
}
int main(){
//    freopen("/Users/shaowei/Desktop/in.txt", "r", stdin);
    int x,tot = 0;
    vec.clear();w.clear();
    ma.clear();
    while(cin >> x) {
        if(x >= 10000){
            vec.push_back(x-10000);
            w.push_back(5);
            all.push_back(x-10000);
        }else if(x >= 0){
            vec.push_back(x);
            w.push_back(1);
            all.push_back(x);
        }else{
            vec.push_back(x);
            w.push_back(0);
            all.push_back(x);
        }
    }
    sort(all.begin(),all.end());
    tot = (int)(unique(all.begin(), all.end()) - all.begin());
    for(int i = 0; i < tot; i++) ma[all[i]] = (int)(lower_bound(all.begin(), all.begin() + tot, all[i]) - all.begin() + 1);
    memset(c, 0, sizeof(c));
    memset(dp, 0, sizeof(dp));
    int maxi = 0;
    for(int i = 0; i < (int)vec.size(); i++){
        dp[i] = qry(ma[vec[i]]) + w[i];
        maxi = max(maxi,dp[i]);
        update(ma[vec[i]], dp[i]);
    }
    cout << maxi << endl;
    return 0;
}
