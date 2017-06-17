/*************************************************************************
> File Name: HDU2203.cpp
> Author:Prgu
> Mail:peter.wfgu@gmail.com
> Created Time: 2017年01月07日 星期六 13时03分52秒
************************************************************************/

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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//int f[100005];
//
//void getfail(const string& pat,int f[]){
//    f[0]=-1;
//    int j=0,k=-1;
//    while(j<pat.length()-1)
//    if(k==-1||pat[k]==pat[j])
//    f[++j]=++k;
//    else
//    k=f[k];
//}
//
//int KMP(const string& ob,const string& pat,int p=0)
//{
//    getfail(pat,f);
//    int i=p,j=0;
//    while(i<ob.length()&&j<pat.length()&&pat.length()-j<=ob.length()-i){
//        if(j==-1||pat[j]==ob[i]){
//            i++;j++;
//        }
//        else
//        j=f[j];
//    }
//    if(j<pat.length())    return -1;
//    else    return i-j;
//}
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    string a,b;
//    while(cin>>a>>b){
//        string c=a+a;
//        if(b.length()>a.length())   {cout<<"no"<<endl;continue;}
//        if(KMP(c,b)!=-1){
//            cout<<"yes"<<endl;
//        }
//        else{
//            cout<<"no"<<endl;
//        }
//    }
//    return 0;
//}
//

//const int maxn=100005;
//char ob[maxn],pat[maxn],newob[maxn*2];
//
//int main(void)
//{
//    while(~scanf("%s",ob)){
//        scanf("%s",pat);
//        strcpy(newob,ob);
//        strcat(newob,ob);
//        if(strstr(newob,pat))
//            cout<<"yes"<<endl;
//        else
//            cout<<"no"<<endl;
//    }
//    return 0;
//}

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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;

ll mod_pow(int x, int n) {
    ll base = x, ans = 1;
    while(n) {
        if(n & 1) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        n >>= 1;
    }
    return ans;
}

const int maxn = 100005;
char a[maxn], b[maxn];
int main(void) {
    while(~scanf("%s", a)) {
        scanf("%s", b);
        int ob = strlen(a);
        int pat = strlen(b);

        ll hash_pat = 0, hash_ob = 0;

        //hash pat
        for(int i = 0; i < pat; i++) {
            int tmp = b[i] - 'A';
            int tmpp = a[i] - 'A';
            hash_pat = (hash_pat % mod + tmp * mod_pow(26, pat - 1 - i) % mod) % mod;
            hash_ob = (hash_ob % mod + tmpp * mod_pow(26, pat - 1 - i) % mod) % mod;
        }

        int flag = 1;
        if(hash_pat == hash_ob) {cout << "yes" << endl; continue;}
        else {
            for(int i = 1; i < ob; i++) {
                int tmp = a[i - 1] - 'A';
                hash_ob = (hash_ob + mod - tmp * mod_pow(26, pat - 1) % mod) % mod;
                hash_ob = (hash_ob * 26) % mod;
                hash_ob += (a[(i + pat - 1) % ob] - 'A') % mod;
                if(hash_ob == hash_pat) {
                    cout << "yes" << endl;
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)    cout << "no" << endl;
        //hash ob and find the same substr

        //O(n*m)  TLE -_-
        // for(int i=0;i<ob;i++){
        //     hash_ob=0;
        //     for(int j=0;j<pat;j++){
        //         int tmp=a[(i+j)%ob]-'A';
        //         hash_ob+=tmp*mod_pow(26,pat-j-1);
        //     }
        //     if(hash_pat==hash_ob){
        //         cout<<"yes"<<endl;
        //         flag=0;
        //         break;
        //     }
        // }
        // if(flag)    cout<<"no"<<endl;

        //O(n)


    }
    return 0;
}
