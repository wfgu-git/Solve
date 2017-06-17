#include<bits/stdc++.h>

using namespace std;

const int maxn=1000+5;
int res[maxn];

int main(void)
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        stack<int> s;
        for(int i=1; i<=n; i++)   cin>>res[i];
        bool flag=true;
        int p=1,q=1;
        while(q<=n)
        {
            if(p==res[q])
            {
                q++;
                p++;
            }
            else if(!s.empty()&&s.top()==res[q])
            {
                s.pop();
                q++;
            }
            else if(p<=n)
            {
                s.push(p++);
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag) cout<<"Yes"<<'\n';
        else    cout<<"NO"<<'\n';
    }
    return 0;
}
