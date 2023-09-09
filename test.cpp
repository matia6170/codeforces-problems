#include <iostream>
#include <vector>

int main() {
    int x = 4;
    int i;
    for (i = 1; i < 3; i++) {
        x *= (i +1);
        x /= 4;
    }
    printf("x = %d", x);

    return 0;
}
