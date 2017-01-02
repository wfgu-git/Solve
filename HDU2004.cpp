#include<iostream>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    int x;
    while(cin>>x){
        if(x>=0&&x<=59)    cout<<"E"<<endl;
        else if(x>=60&&x<=69)    cout<<"D"<<endl;
        else if(x>=70&&x<=79)    cout<<"C"<<endl;
        else if(x>=80&&x<=89)    cout<<"B"<<endl;
        else if(x>=90&&x<=100)    cout<<"A"<<endl;
        else cout<<"Score is error!"<<endl;
    }
}
