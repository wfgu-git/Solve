#include<bits/stdc++.h>
using namespace std;

const int maxn=3000+5;

int bin[16][4]=
{
    {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
    {0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
    {1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
    {1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}
};

char HEX[]= {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int sum[6];
char str[6]= {'A','D','J','K','S','W'};
int m,n,cnt;
int pic[maxn][maxn];

void dfs_white(int r,int c)
{
        cout << "debug: "<< r <<"  "<< c << " :  "<< pic[r][c] << endl;
system("pause");
    if(r<0||r>=m||c<0||c>=n||pic[r][c]!=0)    return;
    pic[r][c]=-1;
    dfs_white(r,c+1);
    dfs_white(r,c-1);
    dfs_white(r+1,c);
    dfs_white(r-1,c);
}

void dfs_black(int r,int c)
{
    cout << "debug: "<< r <<"  "<< c << " :  "<< pic[r][c] << endl;
    system("pause");
    if(r<0||r>=m||c<0||c>=n||pic[r][c]==-1)   return ;
    //只要出现0 肯定是一个洞， 特征值++ 并且把这个洞涂黑 防止重复计算.
    if(pic[r][c]==0)
    {
        cnt++;
        dfs_white(r,c);

    }
    pic[r][c]=-1;
    dfs_black(r,c+1);
    dfs_black(r,c-1);
    dfs_black(r+1,c);
    dfs_black(r-1,c);
}

int main(void)
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    ios::sync_with_stdio(false);
    int kase=0;
    while(cin>>m>>n&&m&&n)
    {
        memset(pic,0,sizeof(pic));
        memset(sum,0,sizeof(sum));
        for(int i=0; i<m; i++)
        {
            char ch;
            int len=0;
            for(int j=0; j<n; j++)
            {
                cin>>ch;
                for(int k=0; k<16; k++)
                {
                    if(HEX[k]==ch)
                    {
                        for(int p=0; p<4; p++)
                            pic[i][len++]=bin[k][p];
                        break;
                    }
                }
            }
        }
        n*=4;
        //先把最外面一层0都赋成-1
        for(int i=0; i<m; i++)
        {
            dfs_white(i,0);
            dfs_white(i,n-1);
        }
        for(int j=0; j<n; j++)
        {
            dfs_white(0,j);
            dfs_white(m-1,j);
        }

//        for(int i=0; i<m; i++)
//        {
//            if(i)   cout<<endl;
//            for(int j=0; j<n; j++)
//                cout<<pic[i][j];
//        }
//        cout<<endl<<endl;
//    }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pic[i][j]==1)
                {
                    cnt=0;
                    dfs_black(i,j);
                    if(cnt==0)  sum[5]++;
                    if(cnt==1)  sum[0]++;
                    if(cnt==2)  sum[3]++;
                    if(cnt==3)  sum[2]++;
                    if(cnt==4)  sum[4]++;
                    if(cnt==5)  sum[1]++;
                }
            }
        }
        printf("Case %d: ",++kase);
        for(int i=0;i<6;i++)
            while(sum[i]--)
                printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
