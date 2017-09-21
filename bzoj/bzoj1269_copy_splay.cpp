#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct abcd{
	abcd *fa,*ls,*rs;
	char c;
	int siz;
	bool rev_mark;
	abcd (char C);
	void Reverse();
	void Push_Up();
	void Push_Down();
}*null=new abcd(0),*root=null;
abcd :: abcd(char C)
{
	fa=ls=rs=null;
	c=C;
	siz=C?1:0;
	rev_mark=0;
}
void abcd :: Reverse()
{
	rev_mark^=1;
	swap(ls,rs);
}
void abcd :: Push_Up()
{
	siz=ls->siz+rs->siz+1;
}
void abcd :: Push_Down()
{
	if(rev_mark)
	{
		ls->Reverse();
		rs->Reverse();
		rev_mark=0;
	}
}
void Zig(abcd *x)
{
	abcd *y=x->fa;
	y->ls=x->rs;
	x->rs->fa=y;
	x->rs=y;
	x->fa=y->fa;
	if(y==y->fa->ls)
		y->fa->ls=x;
	else if(y==y->fa->rs)
		y->fa->rs=x;
	y->fa=x;
	y->Push_Up();
	if(y==root)
		root=x;
}
void Zag(abcd *x)
{
	abcd *y=x->fa;
	y->rs=x->ls;
	x->ls->fa=y;
	x->ls=y;
	x->fa=y->fa;
	if(y==y->fa->ls)
		y->fa->ls=x;
	else if(y==y->fa->rs)
		y->fa->rs=x;
	y->fa=x;
	y->Push_Up();
	if(y==root)
		root=x;
}
void Splay(abcd *x,abcd *Tar)
{
	while(1)
	{
		abcd *y=x->fa,*z=y->fa;
		if(y==Tar)
			break ;
		if(z==Tar)
		{
			if(x==y->ls)
				Zig(x);
			else
				Zag(x);
			break;
		}
		if(x==y->ls)
		{
			if(y==z->ls)
				Zig(y);
			Zig(x);
		}
		else
		{
			if(y==z->rs)
				Zag(y);
			Zag(x);
		}
	}
	x->Push_Up();
}
void Find(abcd *x,int y,abcd *z)
{
	while(1)
	{
		x->Push_Down();
		if(y<=x->ls->siz)
			x=x->ls;
		else
		{
			y-=x->ls->siz;
			if(y==1)
				break;
			y--;
			x=x->rs;
		}
	}
	Splay(x,z);
}
char s[1<<21];
void Build_Tree(abcd *&x,int l,int r)
{
	if(l>r)
		return ;
	int mid=l+r>>1;
	x=new abcd(s[mid]);
	Build_Tree(x->ls,l,mid-1);
	Build_Tree(x->rs,mid+1,r);
	if(x->ls!=null)
		x->ls->fa=x;
	if(x->rs!=null)
		x->rs->fa=x;
	x->Push_Up();
}
int cursor,m;
int main()
{
  freopen("/home/wfgu/solve/data.in", "r", stdin);
	int i,x;
	char p[100];
	cin>>m;
	{
		root=new abcd('\n');
		root->rs=new abcd('\n');
		root->rs->fa=root;
		root->Push_Up();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%s",p);
		if(p[0]=='M')
			scanf("%d",&cursor);
		else if(p[0]=='I')
		{
			scanf("%d",&x);
			do s[0]=getchar(); while(s[0]=='\n'||s[0]=='\r');
			if(x^1) gets(s+1);
			Find(root,cursor+1,null);
			Find(root,cursor+2,root);
			Build_Tree(root->rs->ls,0,x-1);
			root->rs->ls->fa=root->rs;
			root->rs->Push_Up();
			root->Push_Up();
		}
		else if(p[0]=='D')
		{
			scanf("%d",&x);
			Find(root,cursor+1,null);
			Find(root,cursor+x+2,root);
			root->rs->ls=null;
			root->rs->Push_Up();
			root->Push_Up();
		}
		else if(p[0]=='R')
		{
			scanf("%d",&x);
			Find(root,cursor+1,null);
			Find(root,cursor+x+2,root);
			root->rs->ls->Reverse();
		}
		else if(p[0]=='G')
		{
			Find(root,cursor+2,null);
			printf("%c\n",root->c);
		}
		else if(p[0]=='P')
			cursor--;
		else
			cursor++;
	}
}
