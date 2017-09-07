/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

char str[maxn];
int num_array[maxn];
void properfrac2str(int numerator, int denominator, int radix, char str[], int strl)
{
    const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // int *num_array;
    int  find_loop = 0;
    int loop_from, loop_to;
    int i = 0, j;
    if(numerator == 0 || strl <= 1)
    {
        str[0] = 0;
        return;
    }
    memset(num_array, 0, sizeof(num_array));
    // num_array = (int *) malloc(strl * sizeof(int));
    num_array[0] = numerator;

    for (i = 0; i < strl - 3; i++)
    {
        numerator *= radix;
        str[i] = table[numerator / denominator];
        numerator %= denominator;

        if(numerator == 0)
        {
            str[i + 1] = 0;
            break; //finish
        }

        num_array[i + 1] = numerator;

        for(j = 0; j < i; j++)
        {
            if( numerator == num_array[j] ) // Recurring decimal
            {
                loop_from = j;
                loop_to = i;
                //printf("\nloop from %d to %d\n", loop_from, loop_to);
                find_loop = 1;
                break;
            }
        }
        if(find_loop == 1)
        {
            str[loop_to + 2] = ']';
            str[loop_to + 3] = 0;
            for(j = loop_to; j >= loop_from; j --)
            {
                     str[j + 1] =  str[j];
            }
            str[loop_from] = '[';

            break;
        }
    }
    // free(num_array);
}

#define FALSE 0
#define TRUE 1

/**
* 把一整数转换为字符串
* @para num 待转化的整数
* @para str 保存转换后得到的字符串
* @para radix 基数
* @ret 指向生成的字符串
**/
char* itoa ( int num, char* str, int radix )
{
    const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* ptr = str;
    int negative = FALSE;
    if ( num == 0 ) //num=0
    {
        *ptr++ = '0';
        *ptr = '\0'; // don`t forget the end of the string is '\0'!!!!!!!!!
        return str;
    }
    if ( num < 0 ) //if num is negative ,the add '-'and change num to positive
    {
        *ptr++ = '-';
        num *= -1;
        negative = TRUE;
    }
    while ( num )
    {
        *ptr++ = table[num % radix];
        num /= radix;
    }
    *ptr = '\0'; //if num is negative ,the add '-'and change num to positive
// in the below, we have to converse the string
    char* start = ( negative ? str + 1 : str ); //now start points the head of the string
    ptr--; //now prt points the end of the string
    while ( start < ptr )
    {
        char temp = *start;
        *start = *ptr;
        *ptr = temp;
        start++;
        ptr--;
    }
    return str;
}
int frac2str(int numerator, int denominator, int radix, char *str, int strl)
{
    char strIntPart[33];
    int l;
    int intPart;

    int sign = 1;
    if(denominator == 0)
    {
        fprintf(stderr, "ERROR: denominator is 0\n");
        return -2;
    }
    if( (numerator ^ denominator) < 0)
    {
        sign = -1;
        numerator = abs(numerator);
        denominator = abs(denominator);
    }
// reduction of a fraction
    l = __gcd(numerator, denominator);
    numerator /= l;
    denominator /= l;

// seperate the fraction to an integer part and a proper fraction
    intPart = numerator / denominator;
    numerator = numerator % denominator;

    itoa(intPart, strIntPart, radix);
    strcat(strIntPart, ".");
    l = strlen(strIntPart);
    if(sign == -1)
    {
        str[0] = '-';
        str ++;
        strl --;
    }
    if(strl < l)
    {
        fprintf(stderr, "ERROR:string is too short to hold the result!\n");
        return -1;
    }
    strcpy(str, strIntPart);

//    printf("%s", str);
    if(numerator != 0 && strl - l != 0)
    {
        properfrac2str(numerator, denominator, radix, str + l,  strl - l);
    }
    return 0;
}
int check(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else {
    return c - 'a' + 10;
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int base;
    char up[35];
    char down[35];
    scanf("%d%s%s", &base, up, down);
    ll tup = 0;
    ll tdown = 0;
    int dn = strlen(down);
    for (int i = 0; i < dn; ++i) {
      if (down[i] >= 'A' && down[i] <= 'Z') {
        down[i] += 32;
      }
      tdown = tdown * base + check(down[i]);
    }
    int un = strlen(up);
    for (int i = 0; i < un; ++i) {
      if (up[i] >= 'A' && up[i] <= 'Z') {
        up[i] += 32;
      }
      tup = tup * base + check(up[i]);
      tup %= tdown;
    }
    properfrac2str(tup, tdown, base, str, maxn - 1);
    string ret(str);
    int ans = ret.find(']') - ret.find('[') - 1;
    printf("Scenario #%d:\n%d\n\n", cas, ans == -1 ? 0 : ans);
  }
  return 0;
}
