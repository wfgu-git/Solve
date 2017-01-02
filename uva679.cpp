#include<bits/stdc++.h>
using namespace std;
/*直接模拟  超时
const int maxDeepth=20;
int leaves[1<<maxDeepth];

int main(void)
{
    int T;
    while(cin>>T&&T!=-1){
    while(T--)
    {
        memset(leaves,0,sizeof(leaves));
        int num;
        int d,i;
        cin>>d>>i;
        int maxNum=(1<<d)-1;
        for(int k=1;k<=i;k++)
        {
            num=1;
            while(1){
            leaves[num]=!leaves[num];
            num=leaves[num]?2*num:2*num+1;
            if(num>maxNum) break;
            }
        }
        cout<<num/2<<endl;
    }
    }
    return 0;
}

*/
int T;
int D,I;
int main(void)
{
    while(cin>>T&&T!=-1){
        while(T--){
            cin>>D>>I;
            int k=1;
            for(int i=1;i<=D-1;i++)
            {
                if(I%2) {k=k*2;I=(I+1)/2;}
                else    {k=k*2+1;I/=2;}
            }
            cout<<k<<endl;
        }
    }
    return 0;
}
