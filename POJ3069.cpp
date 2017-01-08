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
vector<int> a;

int main()
{
    ios::sync_with_stdio(false);
    int r,n;
    while(cin>>r>>n&&n!=-1&&r!=-1){
        a.clear();
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int ans=0,i=0;
        while(i<n){
            int tmp=a[i];

            while(i<n&&a[i]<=tmp+r) i++; //go ahead

            int p=a[i-1];

            while(i<n&&a[i]<=p+r) i++;

            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
