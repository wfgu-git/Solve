#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 20;

/*
r数组:原始数据
j当前字符串的长度,每次循环根据2个j长度的字符串的排名求得2j长度字符串的排名.
y数组:指示长度为2j的字符串的第二关键字的排序结果,通过存储2j长字符串的第一关键字的下标进行指示.
wv数组:2j长字符串的第一关键字的排名序号.
ws数组:计数数组,计数排序用到.
x数组:一开始是原始数据r的拷贝(其实也表示长度为1的字符串的排名),之后表示2j长度字符串的排名.
p:不同排名的个数.
*/

int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
/*
  cmp函数:参数r为长度为l的字符串的排名数组,
  a和b分别是两个长度为2l的字符串(姑且称为str1和str2)
  的首字符的下标,str1和str2可以分为两个长度为l的
  子串(姑且称为str1'和str1'',str2'和str2''),其中
  str1'和str2'的首字符的下标分别为a和b,str1''和str2''的
  首字符的下标分别为a+l和b+l.那么r[a]和r[b]则表示str1'和str2'的排名,
  r[a+l]和r[b+l]表示str1''和str2''的排名.cmp函数揭示了:
  若str1和str2两个部分的子串的排名都相等,那么str1和str2的排名也相等.
*/
int cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int *r, int *sa, int n, int m) {
  int i, j, p, *x = wa, *y = wb, *t;
  //以下4句是简单的计数排序
  for (i = 0; i < m; i++) ws[i] = 0;
  for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
  for (i = 1; i < m; i++) ws[i] += ws[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
  /*
    每次循环的工作:
    将长度为j的两个子串合并为长度为2j的字符串,
    其中前j个子串为第一关键字,后j个子串为第二关键字,
    并求出这这些2j长的字符串的排名.
  */
  /*每做一次循环,可以得到排名的数量p,由p的值优化m的值,节省空间,这是m=p的理由*/
  for (j = 1, p = 1; p < n; j *= 2, m = p) {
    /*y数组指示的是对第二关键字排序的结果.
      存储的内容是2j长度的字符串的第一关键字的下标.*/
    /*
      n-j到n-1之间的元素,第二关键字为0,
      这些元素在所有字符串中要排在最前.比如论文中的例子"aabaaaab0",
      以0为开始的2j长度的字符串没有第二关键字(视为补0).
    */
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    /*
      只有sa[i]大于等于j的下标,才有可能作为第二关键字进行排序.
      比如"aabaaaab0",当2j为2时,第一个a(下标为0)是不可能作为
      第二关键字的.当2j为4时,前两个a(下标为0和1)是不可能作为第二关键字的.
    */
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    /*以上步骤,已经将第二关键排好序了.接着将2j长度的字符串的第一关键字的排名序号提取到wv中.*/
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    /*以下几行,在第二关键字排好序的基础上,对第一关键字排序*/
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[wv[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
    /*
      通过以上步骤,已经将长度为2j的字符串排序完毕,存放在sa数组中.
      接着由sa数组求得排名数组rank.p表示排名,当两个字符串排名一致时,
      他们的p值相等,否则p向上递增.当p==n时,表示2j长度的字符串的排名
      已经能够互相区分,没有了相同排名的字符串.那么2j+2j长度的字符串的
      排名也能根据此进行区分了,因此当p>=n时循环可以结束了.
    */
    for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
  return;
}



/*
    Problem: JZOJ1598(询问一个字符串中有多少至少出现两次的子串)
    Content: sa's Code and Explanation
    Author : YxuanwKeith
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100005;

char ch[MAXN], All[MAXN];
int sa[MAXN], rnk[MAXN], Height[MAXN], tax[MAXN], tp[MAXN], a[MAXN], n, m;
char str[MAXN];
// rnk[i] 第i个后缀的排名; sa[i] 排名为i的后缀位置; Height[i]
// 排名为i的后缀与排名为(i-1)的后缀的LCP  tax[i] 计数排序辅助数组; tp[i]
// rnk的辅助数组(计数排序中的第二关键字),与sa意义一样。  a为原串
void RSort() {
  // rnk第一关键字,tp第二关键字。
  for (int i = 0; i <= m; i++) tax[i] = 0;
  for (int i = 1; i <= n; i++) tax[rnk[tp[i]]]++;
  for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
  for (int i = n; i >= 1; i--)
    sa[tax[rnk[tp[i]]]--] =
        tp[i];  //确保满足第一关键字的同时，再满足第二关键字的要求
}  //计数排序,把新的二元组排序。

int cmp(int *f, int x, int y, int w) {
  return f[x] == f[y] && f[x + w] == f[y + w];
}
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix() {
  // sa
  for (int i = 1; i <= n; i++) rnk[i] = a[i], tp[i] = i;
  m = 127, RSort();  //一开始是以单个字符为单位，所以(m = 127)

  for (int w = 1, p = 1, i; p < n; w += w, m = p) {  //把子串长度翻倍,更新rnk

    // w 当前一个子串的长度; m 当前离散后的排名种类数
    //当前的tp(第二关键字)可直接由上一次的sa的得到
    for (p = 0, i = n - w + 1; i <= n; i++)
      tp[++p] = i;  //长度越界,第二关键字为0
    for (i = 1; i <= n; i++)
      if (sa[i] > w) tp[++p] = sa[i] - w;

    //更新sa值,并用tp暂时存下上一轮的rnk(用于cmp比较)
    RSort(), swap(rnk, tp), rnk[sa[1]] = p = 1;

    //用已经完成的sa来更新与它互逆的rnk,并离散rnk
    for (i = 2; i <= n; i++)
      rnk[sa[i]] = cmp(tp, sa[i], sa[i - 1], w) ? p : ++p;
  }
  //离散：把相等的字符串的rnk设为相同。
  // LCP
  int j, k = 0;
  for (int i = 1; i <= n; Height[rnk[i++]] = k)
    for (k = k ? k - 1 : k, j = sa[rnk[i] - 1]; a[i + k] == a[j + k]; ++k)
      ;
  //这个知道原理后就比较好理解程序
}

void init() {
  scanf("%s", str);
  n = strlen(str);
  for (int i = 0; i < n; i++) a[i + 1] = str[i];
}

int main() {
  init();
  Suffix();

  int ans = Height[2];
  for (int i = 3; i <= n; i++) ans += max(Height[i] - Height[i - 1], 0);
  printf("%d\n", ans);
}
