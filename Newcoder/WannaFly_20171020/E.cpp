/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void work() {
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
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
