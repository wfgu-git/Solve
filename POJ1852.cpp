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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn=1000000;
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int l,n;
        cin>>l>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int mint=0,maxt=0;
        for(int i=0;i<n;i++){
            mint=max(mint,min(a[i],l-a[i]));
            maxt=max(maxt,max(a[i],l-a[i]));
        }
        cout<<mint<<" "<<maxt<<endl;
    }
    return 0;
}
