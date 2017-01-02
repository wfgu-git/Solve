#include<cstdio>
#include<cmath>
using namespace std;

double solve(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main(void)
{
    double x1,x2,y1,y2;
    while(~scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)){
        double ans=solve(x1,y1,x2,y2);
        printf("%.2f\n",ans);
    }
    return 0;
}
