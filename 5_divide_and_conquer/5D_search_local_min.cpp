#include <iostream>
#include <limits>
#include <vector>

using namespace std;

enum Slope {
    Maximum,     // 1
    Increasing,  // 2
    Decreasing,  // 3
    Minimum,     // 4
};

int determineIncreasing(vector<int>& guessed, int idx) {
    for (int i = idx - 1; i <= idx + 1; i++) {
        if (guessed[i] == -1) {
            printf("? %s\n", to_string(i));
            scanf("%d", &guessed[i]);
        }
    }
    int l = guessed[idx - 1];
    int r = guessed[idx + 1];
    int c = guessed[idx];
    if (l > c && r > c) {
        return 4;
    }
    if (l < c && r < c) {
        return 1;
    }
    if (r > c) {
        return 2;
    }
    return 3;
}

bool findLocalMinimum(vector<int> guessed, int l, int h) {
    while (l <= h) {
        int m = (l + h) / 2;
        switch (determineIncreasing(guessed, m)) {
            case 4:
                cout << "! " << m << endl;
                printf("~")
                return true;
            case 2:
                h = m - 1;
                break;
            case 3:
                l = m + 1;
                break;
            case 1:
                if (findLocalMinimum(guessed, l, m - 1)) return true;
                return findLocalMinimum(guessed, m + 1, h);
        }
    }
    return false;
}

void findLocalMinimum(int n) {
    vector<int> guessed(n + 1, -1);
    guessed[0] = numeric_limits<int>::max();
    guessed.push_back(numeric_limits<int>::max());
    findLocalMinimum(guessed, 1, n);
}


int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    findLocalMinimum(n);
}