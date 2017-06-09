#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int basea = 1, baseb = 2;
    while(true){
        if(a < basea) {
            cout << "Vladik" << endl;
            break;
        }
        a -= basea;
        basea += 2;
        if(b < baseb){
            cout << "Valera" << endl;
            break;
        }
        b -= baseb;
        baseb += 2;
    }
    return 0;
}

