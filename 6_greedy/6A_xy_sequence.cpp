#include <stdio.h>

int main() {
    long long int t, n, B, x, y;
    long long int ax, ay, sum = 0, lastA = 0;

    scanf("%lld", &t);

    for (int i = 0; i < t; ++i) {
        scanf("%lld %lld %lld %lld", &n, &B, &x, &y);

        lastA = 0;

        for (int j = 1; j <= n; ++j) {
            ax = lastA + x;
            ay = lastA - y;
            if (ax > ay && ax <= B) {
                sum += ax;
                lastA = ax;
            } else if (ay <= B && ay <= B) {
                sum += ay;
                lastA = ay;
            }
        }
        printf("%lld\n", sum);
        sum = 0;
    }
}