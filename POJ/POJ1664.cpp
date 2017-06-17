// 缁勫悎鏁板
#include<iostream>
using namespace std;
//f(m,n)  m涓嫻鏋滄斁鍏涓洏瀛愮殑鏂规硶鏁�
int solve(int m,int n)
{
    if(m==0||n==1)    return 1;
    if(n>m) return solve(m,m);
    else{
        return solve(m,n-1)+solve(m-n,n);
    }
}
int m,n,T;
int main(void)
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>m>>n;
        cout<<solve(m,n)<<endl;
    }
    return 0;
}

