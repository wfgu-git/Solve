// // #include <cstdio>
// // using namespace std;

// // void print_permutation(int n, int *a, int cur) {
// //     if(cur == n) {
// //         for(int i = 0; i < n; i++) {
// //             printf("%d ", a[i]);
// //         }
// //         printf("\n");
// //     } else {
// //         for(int i = 1; i <= n; i++) {
// //             bool used = false;
// //             for(int j = 0; j < cur; j++) {
// //                 if(a[j] == i)  used = true;
// //             }
// //             if(!used) {
// //                 a[cur] = i;
// //                 print_permutation(n, a, cur + 1);
// //             }
// //         }
// //     }
// // }

// // int main(int argc, char const *argv[]) {
// //     int n;
// //     while(~scanf("%d", &n)) {
// //         int *a;
// //         a = new int[n + 5];
// //         print_permutation(n, a, 0);
// //         delete[] a;
// //     }
// //     return 0;
// // }
// #include <cstdio>
// using namespace std;

// int p[] = {1, 1, 1};
// int a[100];
// void print_permutation(int n, int *limit, int *a, int cur) {
//     if(cur == n) {
//         for(int i = 0; i < n; i++) {
//             printf("%d ", a[i]);
//         }
//         printf("\n");
//     } else {
//         for(int i = 0; i < n; i++) {
//             if(!i || p[i] != p[i - 1]) {
//                 int c1 = 0, c2 = 0;
//                 for(int j = 0; j < cur; j++) {
//                     if(a[j] == p[i])
//                         c1++;
//                 }
//                 for(int j = 0; j < n; j++) {
//                     if(p[i] == p[j])
//                         c2++;
//                 }
//                 if(c1 < c2) {
//                     a[cur] = p[i];
//                 }
//                 print_permutation(n, p, a, cur + 1);
//             }
//         }
//     }
// }

// int main(int argc, char const *argv[]) {
//     print_permutation(3, p, a, 0);
//     return 0;
// }

#include <cstdio>

int a[1000];
void print_subset(int n, int *a, int cur) {
    for(int i = 0; i < cur; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int s = cur ? a[cur - 1] + 1 : 0;
    for(int i = s; i < n; i++) {
        a[cur] = i;
        print_subset(n, a, cur + 1);
    }
}
int main(int argc, char const *argv[]) {
    print_subset(5, a, 0);
    return 0;
}