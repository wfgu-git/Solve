#include<cstdio>
#include<iostream>
#include<ext/rope>
#include<algorithm>
using namespace std;
using namespace __gnu_cxx;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,now,len;
rope <char> a,b,tmp;
char s[2000000],rs[2000000];
int main()
{
  freopen("/home/wfgu/solve/data.in", "r", stdin);
	n=read();
	int x;
	while(n--)
	{
		scanf("%s",s);
		switch(s[0])
		{
		case 'M':now=read();break;
		case 'P':now--;break;
		case 'N':now++;break;
		case 'G':printf("%c\n",a[now]);break;
		case 'I':
		{
			x=read();len=a.length();
			for(int i=0;i<x;i++)
			{
				s[i]=getchar();
				while(s[i]=='\n')
					s[i]=getchar();
				rs[x-i-1]=s[i];
			}
			rs[x]=s[x]=0;
			a.insert(now,s);
			b.insert(len-now,rs);
			break;
		}
		case 'D':
		{
			x=read();len=a.length();
			a.erase(now,x);
			b.erase(len-now-x,x);
			break;
		}
		case 'R':
		{
			x=read();len=a.length();
			tmp=a.substr(now,x);
			a=a.substr(0,now)+b.substr(len-now-x,x)+a.substr(now+x,len-now-x);
			b=b.substr(0,len-now-x)+tmp+b.substr(len-now,now);
			break;
		}
		}
	}
	return 0;
}
