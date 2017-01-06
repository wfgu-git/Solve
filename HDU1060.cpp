/*************************************************************************
 *  > File Name: hdu1060.cpp
 *      > Author:Prgu 
 *          > Mail:peter.wfgu@gmail.com 
 *              > Created Time: 2016年12月29日 星期四 18时31分04秒
 *               ************************************************************************/

 #include<iostream>
 #include<algorithm>
 #include<string>
 #include<vector>
 #include<map>
 #include<cstring>
 #include<cstdio>
 #include<cmath>
 #include<cstdlib>
 #include<stack>
 #include<iomanip>
 #include<cctype>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ull;
 int main(void)
 {
         int T;
         cin>>T;
     while(T--){
                 ll n;
                 cin>>n;
                 double ans=n*log10(n*1.0);
                 ans=ans-(ll)ans;
                 ans=pow(10.0,ans);
                 cout<<(ll)ans<<endl;
             
     }
         return 0;

}
