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
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
string s;
int main()
{
    cin>>s;
    if(s.length()==1) {cout<<s;return 0;}
    int op=0;
    sort(s.begin(),s.end());
    while(true){
        if(s[++op]!='+') break;
    }
    for(int i=op;i<(int)s.length();i++){
        cout<<s[i];
        if(i!=s.length()-1) cout<<'+';
    }
    cout<<endl;
    return 0;
}
