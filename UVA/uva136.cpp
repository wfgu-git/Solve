#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int coeff[3]={2,3,5};

int main(void)
{
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    //越小的整数优先级越大
    //即从小到大排列的队列
    set<ll> s;
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++)
    {
        ll x=pq.top();pq.pop();
        if(i==1500)
        {
            cout<<"The 1500'th ugly number is "<<x<<'.'<<endl;
            break;
        }
        for(int j=0;j<3;j++)
        {
            ll x2=x*coeff[j];
            if(!s.count(x2))
            {
                s.insert(x2);
                pq.push(x2);
            }
        }

    }
    return 0;
}
