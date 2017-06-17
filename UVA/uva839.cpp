#include<bits/stdc++.h>
using namespace std;

bool solve(int &W)  //w是子天平的总重量
{
    int W1,D1,W2,D2;
    bool b1=true,b2=true;
    cin>>W1>>D1>>W2>>D2;
    if(!W1)  b1=solve(W1);
    if(!W2)  b2=solve(W2);
    //递归输入
    W=W1+W2;
    return b1&&b2&&(W1*D1==W2*D2);
}

int main()
{
    int T,W;
    cin>>T;
    while(T--)
    {
        if(solve(W))    cout<<"YES\n";
        else    cout<<"NO\n";

        if(T)   cout<<"\n";
    }
    return 0;
}
