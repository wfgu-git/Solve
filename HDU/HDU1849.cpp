/*************************************************************************
	> File Name: HDU1849.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月06日 星期五 18时56分58秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void)
{
        int n;
    while(cin>>n&&n){
                int x;
                cin>>x;
                int  sum=x;
        while(--n){
                        cin>>x;
                        sum^=x;
                    
        }
                if(!sum)
                    cout<<"Grass Win!"<<endl;
                else
                    cout<<"Rabbit Win!"<<endl;

            
    }
        return 0;

}
