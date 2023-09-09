#include <stdio.h>

#include <vector>
#include <climits>


using namespace std;

int main() {
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);


        int value, max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for (int j = 0; j < n; j++) {
            scanf("%d", &value);
            if (value > max1) {
                max2 = max1;
                max1 = value;
            } else if (value > max2) {
                max2 = value;
            }
            if (value < min1) {
                min2 = min1;
                min1 = value;
            } else if (value < min2) {
                min2 = value;
            }
        }
        
        printf("%d\n", max1 + max2 - min1 - min2);
    }

    return 0;
}