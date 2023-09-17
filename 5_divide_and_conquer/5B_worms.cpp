#include <iostream>
#include <vector>

using namespace std;
//binary search

int main() {
    int n;
    vector<int> limit;
    int sum = 0;
    scanf("%d", &n);
    limit.push_back(0);
    for (int i = 0; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        sum += a;
        limit.push_back(sum);
    }



    int m = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, j = 0;
        scanf("%d", &a);
        int left = 0, right = limit.size() - 1, mid;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (a > limit[mid]) {
                left = mid;
            } else if (a == limit[mid]) {
                right = mid;
                break;
            } else {
                right = mid ;
            }
        }

        printf("%d\n", right);
    }
}

