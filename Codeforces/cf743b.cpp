#include <bits/stdc++.h>
using namespace std;

bool Isjs(long long x) {
    if(x % 2 == 0) return 0;
    else
        return 1;
}

int main(int argc, char const *argv[]) {
    int n;
    long long k;
    while(~scanf("%d%lld", &n, &k)) {
        if(k % 2 == 1) {
            printf("1\n");
            continue;
        }
        int cnt = 2;
        long long i = 2;
        while(!Isjs(k / i)) {
            cnt++;
            i *= 2;
        }
        cout << cnt << endl;

    }
    return 0;
}
