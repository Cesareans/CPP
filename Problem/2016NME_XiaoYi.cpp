/*
 * Easy - 简单模拟题
 */
#include <cstdio>

int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}

int main() {
    int n, a;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &a);
        int t;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t);
            a+=(a>=t?t:gcd(a,t));
        }
        printf("%d\n", a);
    }
    return 0;
}