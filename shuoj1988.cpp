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

struct date{
    int sec,min,hour,day;
    date operator+(date b){
        date res;
        res.sec=res.min=res.hour=res.day=0;
            res.sec=sec+b.sec;
            res.min=min+b.min;
            res.hour=hour+b.hour;
            res.day=day+b.day;
            if(res.sec>=60){
                res.sec-=60;res.min++;
            }
            
            if(res.min>=60){
                res.min-=60;res.hour++;
            }
            if(res.hour>=24){
                res.hour-=24;res.day++;
            }
        
        return res;
        }
};

date d[2];

int main()
{
    ios::sync_with_stdio(false);
    int a[4];
    while(cin>>d[0].day>>d[0].hour>>d[0].min>>d[0].sec){
        cin>>d[1].day>>d[1].hour>>d[1].min>>d[1].sec;
        date tmp=d[0]+d[1];
        a[0]=tmp.day,a[1]=tmp.hour,a[2]=tmp.min,a[3]=tmp.sec;

        for(int i=0;i<4;i++){
            if(i) cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
