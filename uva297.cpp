#include<bits/stdc++.h>
using namespace std;

const int len=32;
const int maxn=1024;
char s[maxn];
int buf[len][len],cnt;

//左上角坐标是 (r,c) 边长w的缓冲区

void draw(const char *s,int &p,int r,int c,int w)
{
    char ch=s[p++];
    if(ch=='p')
    {
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }
    else if(ch=='f')
    {
        for(int i=r; i<r+w; i++)
            for(int j=c; j<c+w; j++)
                if(buf[i][j]==0)
                {
                    buf[i][j]=1;
                    cnt++;
                }
    }
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(buf,0,sizeof(buf));
        cnt=0;
        for(int i=0;i<2;i++)
        {
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}
