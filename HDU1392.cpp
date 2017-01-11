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
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn=110;

struct Point{
    int x,y;
    Point(){};
    Point(int a,int b):x(a),y(b){};
    friend Point operator+(const Point&a,const Point& b) {return Point(a.x+b.x,a.y+b.y);}
    friend Point operator-(const Point&a,const Point& b) {return Point(a.x-b.x,a.y-b.y);}
};

double dot(const Point& p,const Point& q)
{
    return p.x*q.x+p.y*q.y;
}

double det(const Point& p,const Point& q)
{
    return p.x*q.y-p.y*q.x;
}

int sqr(int x)
{
    return x*x;
}

double norm(const Point& p)
{
    return sqrt(sqr(p.x)+sqr(p.y));
}

double dist(const Point& p,const Point& q)
{
    return norm(p-q);
}

bool cmp_x(const Point& p1, const Point& p2)
{
    if(p1.x!=p2.x) return p1.x<p2.x;
    return p1.y<p2.y;
}

vector<Point> convex_hull(Point* ps,int n)
{
    sort(ps,ps+n,cmp_x);
    int k=0;
    vector<Point> qs(n*2);

    for(int i=0;i<n;i++){
        while(k>1 && det((qs[k-1]- qs[k-2]),(ps[i]-qs[k-1])) <=0) k--;
        qs[k++] = ps[i];
    }

    for(int i=n-2,t=k;i>=0;i--){
        while(k>t&& det((qs[k-1]-qs[k-2]),(ps[i]-qs[k-1])) <=0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}


int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n&&n){
        Point ps[maxn];
        for(int i=0;i<n;i++){
            cin>>ps[i].x>>ps[i].y;
        }

        vector<Point> qs=convex_hull(ps,n);
        double ans=0;
        int k=(int)qs.size();
        for(auto &p : qs){
            cout<<'('<<p.x<<','<<p.y<<')'<<endl;
        }
        for(int i=0;i<k;i++){
            ans+=dist(qs[i],qs[(i+1)%k]);
        }
        if(k==2) ans/=2.0;
        cout<<fixed<<setprecision(2)<<ans<<endl; 
        qs.clear();
        MEM(ps,0);
    }
    return 0;
}
