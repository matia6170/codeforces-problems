#include <stdio.h>
int main() {
    using namespace std;

    unsigned long long int left = 0, right = 10e18, mid = right / 2;

    char input[10];

    while (true) {
        printf("%llu\n", mid);
        fflush(stdout);
        scanf("\n%s", input);
        if (input[0] == 'C') return 0;
        if (input[0] == 'H') {
            left = mid;
            mid += (right - mid) / 2;
        } else if (input[0] == 'L') {
            right = mid;
            mid -= (mid - left) / 2;
        }
    }
}