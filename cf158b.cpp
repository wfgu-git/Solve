#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<queue>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
int n;
int a[100005];
bool cmp(int a, int b) {return a > b;}
int main()
{
    cin >> n;
    int cnt1, cnt2, cnt3, cnt4;
    cnt1 = cnt2 = cnt3 = cnt4 = 0;
    int x;
    while (n--) {
        cin >> x;
        if (x == 4)    cnt4++;
        else if (x == 3) cnt3++;
        else if (x == 2) cnt2++;
        else cnt1++;
    }
    int ans = 0;
    ans += cnt4;
    ans += cnt3;
    cnt1 -= cnt3;
    ans += cnt2 / 2;
    cnt2 %= 2;
    if (cnt2) {
        ans++;
        cnt1 -= 2;
    }
    if (cnt1 > 0) {
        ans += cnt1 / 4;
        if (cnt1 % 4)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
