#include<cstdio>

const double pi=3.1415927;

int main(void)
{
    double r;
    while(~scanf("%lf",&r)){
        double v=r*r*r*4.0*pi/3.0;
        printf("%.3f\n",v);
    }
    return 0;
}
