//Life has never been fucking so easy...
//...Acm without girlfriend
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<functional>
#include<memory>
#include<utility>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cctype>
#include<cstdlib>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

map<string, int> cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while(getline(cin, s)) {
        if(s == "####") {
            int retCnt = 0;
            string retStr;
            for(auto kv : cnt) {
                if(kv.second > retCnt) {
                    retCnt = kv.second;
                    retStr = kv.first;
                }
            }
            cout << retStr << ":" << retCnt << endl;
            cnt.clear();
        }
        string pre, cur;
        pre = cur = "";
        int length = s.size();
        for(int i = 0; i < length; i++) {
            if(s[i] == ' ') {
                if(pre != "" && cur != "") {
                    cnt[pre + ' ' + cur]++;
                }
                if(cur != "") {
                    pre = cur;
                    cur = "";
                }
            } else if(s[i] == '.' || s[i] == ',') {
                if(pre != "" && cur != "") {
                    cnt[pre + ' ' + cur]++;
                }
                pre = cur = "";
            } else {
                cur.push_back(s[i]);
            }
        }
        if(pre != "" && cur != "") {
            cnt[pre + ' ' + cur]++;
        }
    }
    return 0;
}
