/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int ten[4] = {1,10,100,1000};
typedef struct BigNumber
{
    int d[1200];
    BigNumber(string s)
    {
        int i, j, k, len;
        len = s.size();
        d[0] = (len-1)/4+1;
        for(i=1;i<=1199;i++)
            d[i] = 0;
        for(i=len-1;i>=0;i--)
        {
            j = (len-i-1)/4+1;
            k = (len-i-1)%4;
            d[j] += ten[k]*(s[i]-'0');
        }
        while(d[0]>1 && d[d[0]]==0)
            --d[0];
    }
    BigNumber()
    {
        *this = BigNumber(string("0"));
    }
    string toString()
    {
        int i, j, temp;
        string s("");
        for(i=3;i>=1;i--)
        {
            if(d[d[0]]>=ten[i])
                break;
        }
        temp = d[d[0]];
        for(j=i;j>=0;j--)
        {
            s = s+(char)(temp/ten[j]+'0');
            temp %= ten[j];
        }
        for(i=d[0]-1;i>0;i--)
        {
            temp = d[i];
            for(j=3;j>=0;j--)
            {
                s = s+(char)(temp/ten[j]+'0');
                temp %= ten[j];
            }
        }
        return s;
    }
}BigNumber;
BigNumber zero("0"), d, temp, mid[15];
bool operator < (const BigNumber &a, const BigNumber &b)
{
    int i;
    if(a.d[0]!=b.d[0])
        return a.d[0]<b.d[0];
    for(i=a.d[0];i>0;i--)
    {
        if(a.d[i]!=b.d[i])
            return a.d[i]<b.d[i];
    }
    return 0;
}
BigNumber operator + (const BigNumber &a, const BigNumber &b)
{
    int i, x;
    BigNumber c;
    c.d[0] = max(a.d[0], b.d[0]);
    x = 0;
    for(i=1;i<=c.d[0];i++)
    {
        x = a.d[i]+b.d[i]+x;
        c.d[i] = x%10000;
        x /= 10000;
    }
    while(x!=0)
    {
        c.d[++c.d[0]] = x%10000;
        x /= 10000;
    }
    return c;
}
BigNumber operator - (const BigNumber &a, const BigNumber &b)
{
    int i, x;
    BigNumber c;
    c.d[0] = a.d[0];
    x = 0;
    for(i=1;i<=c.d[0];i++)
    {
        x = 10000+a.d[i]-b.d[i]+x;
        c.d[i] = x%10000;
        x = x/10000-1;
    }
    while((c.d[0]>1) && (c.d[c.d[0]]==0))
        --c.d[0];
    return c;
}
BigNumber operator * (const BigNumber &a, const BigNumber &b)
{
    int i, j, x;
    BigNumber c;
    c.d[0] = a.d[0]+b.d[0];
    for(i=1;i<=a.d[0];i++)
    {
        x = 0;
        for(j=1;j<=b.d[0];j++)
        {
            x = a.d[i]*b.d[j]+x+c.d[i+j-1];
            c.d[i+j-1] = x%10000;
            x /= 10000;
        }
        c.d[i+b.d[0]] = x;
    }
    while((c.d[0]>1) && (c.d[c.d[0]]==0))
        --c.d[0];
    return c;
}
bool smaller(const BigNumber &a, const BigNumber &b, int delta)
{
    int i;
    if(a.d[0]+delta!=b.d[0])
        return a.d[0]+delta<b.d[0];
    for(i=a.d[0];i>0;i--)
    {
        if(a.d[i]!=b.d[i+delta])
            return a.d[i]<b.d[i+delta];
    }
    return 1;
}
void Minus(BigNumber &a, const BigNumber &b, int delta)
{
    int i, x;
    x = 0;
    for(i=1;i<=a.d[0]-delta;i++)
    {
        x = 10000+a.d[i+delta]-b.d[i]+x;
        a.d[i+delta] = x%10000;
        x = x/10000-1;
    }
    while((a.d[0]>1) && (a.d[a.d[0]]==0))
        --a.d[0];
}
BigNumber operator * (const BigNumber &a, int k)
{
    BigNumber c;
    c.d[0] = a.d[0];
    int i, x;
    x = 0;
    for(i=1;i<=a.d[0];i++)
    {
        x = a.d[i]*k+x;
        c.d[i] = x%10000;
        x /= 10000;
    }
    while(x>0)
    {
        c.d[++c.d[0]] = x%10000;
        x /= 10000;
    }
    while((c.d[0]>1) && (c.d[c.d[0]]==0))
        --c.d[0];
    return c;
}
BigNumber operator / (const BigNumber &a, const BigNumber &b)
{
    int i, j, temp;
    BigNumber c;
    d = a;
    mid[0] = b;
    for(i=1;i<=13;i++)
        mid[i] = mid[i-1]*2;
    for(i=a.d[0]-b.d[0];i>=0;i--)
    {
        temp = 8192;
        for(j=13;j>=0;j--)
        {
            if(smaller(mid[j], d, i))
            {
                Minus(d, mid[j], i);
                c.d[i+1] += temp;
            }
            temp /= 2;
        }
    }
    c.d[0] = max(1, a.d[0]-b.d[0]+1);
    while((c.d[0]>1) && (c.d[c.d[0]]==0))
        --c.d[0];
    return c;
}

void work() {
  int T;
  cin >> T;
  string str1, str2;
  while (T--) {
    cin >> str1 >> str2;
    BigNumber n(str1);
    BigNumber m(str2);
    BigNumber k("1");
    BigNumber base("2");
    while (k * m < n + m) { // (k - 1) * m < n
      k = k * 2;
    }
    BigNumber ans("0");
    while (zero < n) {
      while (((k * m) < (n + m)) == 0) k = k / base;

      ans = ans + k;

      if (n < k * m) {
        n = n / k;
        n = d;
      } else {
        n = n - k * m;
      }
    }
    cout << ans.toString() << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  // freopen("data.in", "r", stdin);
  work();
}
