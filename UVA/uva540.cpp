#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;

int main(void)
{
    int t,kase=0;
    while(~scanf("%d",&t)&&t)
    {
        printf("Scenario #%d\n",++kase);
        map<int,int> team;
        for(int i=0;i<t;i++)
        {
            int n,x;
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&x);
                team[x]=i;
            }
        }

        queue<int> q,q2[maxn];
        for(;;)
        {
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if(cmd[0]=='S') break;
            else if(cmd[0]=='D')
            {
                int t=q.front();
                printf("%d\n",q2[t].front());
                q2[t].pop();
                if(q2[t].empty()) q.pop();
            }
            else if(cmd[0]=='E')
            {
                scanf("%d",&x);
                int t=team[x];
                if(q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
