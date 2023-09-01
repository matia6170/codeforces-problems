// #include <iostream>
#include <stdio.h>

int main() {
    int add, sub;

    while (scanf("%d %d", &add, &sub) != EOF) {
        
        int tot = 0;

        for (int i = 0; i < add; i++) {
            int a;
            scanf("%d", &a);
            tot += a;
        }

        for (int i = 0; i < sub; i++) {
            int b;
            scanf("%d", &b);
            tot -= b;
        }

        printf("%d\n", tot);
    }
}
