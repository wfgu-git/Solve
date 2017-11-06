#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//0！，1！，2！... ... (n-1)!，n!中有多少数的末尾0个数是偶数-->含5偶数的个数

LL dp[27];

LL q_pow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int main()
{
    /*
    表用于求出dp[k]表示[0,5^k)内含有偶数5因子数的个数
    表中0表示偶数个5,1表示奇数个5
    printf("0: 0\n");
    printf("1: 00000\n");
    printf("2: 0000011111000001111100000\n");
    printf("3: 0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("4: 0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    printf("   0000011111000001111100000\n");
    for(int i=125;i<625;i++)
    {
        if(i%25==0) printf("   ");
        int temp=0;
        temp+=i/5;
        temp+=i/25;
        temp+=i/125;
        if(temp&1) printf("1");
        else printf("0");
        if(i%25==24) printf("\n");
    }
    观察出if(k&1) dp[k]=5*dp[k-1];
    else dp[k]=3*d[k-1]+2*(5^(k-1)-dp[k-1]);
    log5(10^18)<27
    */
    dp[0]=1;
    for(int k=1;k<27;k++)
        if(k&1) dp[k]=5*dp[k-1];
    	else dp[k]=3*dp[k-1]+2*(q_pow(5,k-1)-dp[k-1]);
    ios::sync_with_stdio(false);
    LL n;
    while(cin>>n)
    {
        if(n==-1) break;
        //因为从0开始计数，所以n需要+1再进行5进制分解
        n++;
        //k从高位开始分解
        LL ans=0,k=26;
        //开关表示是否进入翻转区
        bool on=1;
        while(k>=0)
        {
            //c表示用了dp[k]的c个段去表示不完整的dp[k+1]
            int c=n/q_pow(5,k);
            if(k&1)
            {
                //如果是奇数去表示下一层，会出现ans(~ans)ans(~ans)的情况
                if(on)
                {
                    switch(c)
                    {
                        case 0: break;
                        //1的时候用完ans，下一段进入~ans
                        case 1: ans+=dp[k];on=!on;break;
                        case 2: ans+=dp[k]+(q_pow(5,k)-dp[k]);break;
                        //3的时候用完ans(~ans)ans，下一段进入~ans
                        case 3: ans+=2*dp[k]+(q_pow(5,k)-dp[k]);on=!on;break;
                        case 4: ans+=2*dp[k]+2*(q_pow(5,k)-dp[k]);break;
                    }
                }
                else
                {
                    switch(c)
                    {
                        case 0: break;
                        //1的时候用完(~ans)，下一段进入ans
                        case 1: ans+=(q_pow(5,k)-dp[k]);on=!on;break;
                        case 2: ans+=(q_pow(5,k)-dp[k])+dp[k];break;
                        //3的时候用完(~ans)ans(~ans)，下一段进入ans
                        case 3: ans+=2*(q_pow(5,k)-dp[k])+dp[k];on=!on;break;
                        case 4: ans+=2*(q_pow(5,k)-dp[k])+2*dp[k];break;
                    }
                }
            }
            else
            {
                //如果是偶数去表示不影响
                if(on) ans+=c*dp[k];
                else ans+=c*(q_pow(5,k)-dp[k]);
            }
            n-=c*q_pow(5,k);
            k--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
