#include<stdio.h>  
#include<string.h>
#include<iostream>
using namespace std;

const int maxn = 40000;
int f[70][maxn];
int value[70][3],imp[70][3];

int main()
{
    int n,m;
    int v,p,q;

    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&v,&p,&q);
        //为主件
        if (!q)
        {
            value[i][0] = v;
            imp[i][0] = p;
        }
        //为附件
        else
        {
            if (!value[q][1])
            {
                value[q][1] = v;
                imp[q][1] = p;
            }
            else
            {
                value[q][2] = v;
                imp[q][2] = p;
            }
        }
    }

    memset(f,0,sizeof(f));
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (j-value[i][0]>=0)
            {
                //仅主件
                f[i][j] = max(f[i-1][j],f[i-1][j-value[i][0]] + value[i][0]*imp[i][0]);
                //这个时候的f[i][j]表示仅有主件的时候的情况，而下面每种加附件的情况，都是在有主件的基础下，所以
                //直接和f[i][j]比较
                //主件 + 附件1
                if (j-value[i][0]-value[i][1]>=0)
                    f[i][j] = max(f[i][j],f[i-1][j-value[i][0]-value[i][1]] + value[i][0]*imp[i][0] + value[i][1]*imp[i][1]);
                //主件 + 附件2
                if (j-value[i][0]-value[i][2]>=0)
                    f[i][j] = max(f[i][j],f[i-1][j-value[i][0]-value[i][2]] + value[i][0]*imp[i][0] + value[i][2]*imp[i][2]);
                //主件 + 所有附件
                if (j-value[i][0]-value[i][1]-value[i][2]>=0)
                    f[i][j] = max(f[i][j],f[i-1][j-value[i][0]-value[i][1]-value[i][2]] + value[i][0]*imp[i][0] + value[i][1]*imp[i][1] + value[i][2]*imp[i][2]);
            }
            else
                f[i][j] = f[i-1][j];
        }
    }
    printf("%d\n",f[m][n]);
    return 0;
}
