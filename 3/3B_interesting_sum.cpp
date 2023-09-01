#include <stdio.h>

#include <climits>

int max(int* arr, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int min(int* arr, int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void getSubArray(int* arr, int size, int* subArr, int start, int end) {
    for (int i = 0; i < end - start + 1; i++) {
        subArr[i] = arr[i + start];
    }
}

int getBeautyVal(int* arr, int size, int l, int r) {
    printf("==calc beauty...==\n");
    int subArray[r - l + 1];
    getSubArray(arr, size, subArray, l, r);

    int notSubArraySize = size - (r - l + 1);
    int notSubArray[notSubArraySize];
    for (int i = 0; i < l; i++) {
        notSubArray[i] = arr[i];
    }
    for (int i = r + 1; i < size+1; i++) {
        notSubArray[l + i] = arr[i];
    }
    for (int i = 0; i < notSubArraySize; i++) {
        printf("%d ", notSubArray[i]);
    }
    printf("\n");

    return max(notSubArray, notSubArraySize) -
           min(notSubArray, notSubArraySize) + max(subArray, r - l + 1) -
           min(subArray, r - l + 1);
}

int main() {
    using namespace std;

    int testCases;

    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++) {
        int n;
        scanf("%d", &n);
        int numbers[n];

        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            numbers[j] = a;
        }

        int beautyTemp = max(numbers, n) - min(numbers, n);

        int maxBeauty = INT_MIN;
        int maxb[2];

        printf("=====\n i: %d\n", i);
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (r - l + 1 != n) {
                    int subArray[r - l + 1];
                    getSubArray(numbers, n, subArray, l, r);

                    int beautyVal = getBeautyVal(numbers, n, l, r);
                    printf("l: %d || r: %d || bVal: %d\n", l, r, beautyVal);
                    if (beautyVal >= maxBeauty) {
                        maxBeauty = beautyVal;
                        maxb[0] = l;
                        maxb[1] = r;
                    }
                    printf("========\n");
                }
            }
        }

        printf("max: %d\n", maxBeauty);
        printf("maxl: %d || maxr: %d\n", maxb[0], maxb[1]);
        printf("--------------------\n");
        int test[10] = {9, 2, 5, 9, 8, 9, 7, 5, 0, 6};
        // printf("max: %d || min: %d\n", max(test, 10), min(test, 10));
        //  int a = 8, b=9;
        //  int testSubArray[b - a + 1];
        //  getSubArray(test, n, testSubArray, a, b);
        //  for (int i = 0; i < b - a + 1; i++) {
        //      printf("%d ", testSubArray[i]);
        //  }
    }
}