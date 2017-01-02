组合数学
#include<iostream>
using namespace std;
//f(m,n)  m个苹果放入n个盘子的方法数
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

