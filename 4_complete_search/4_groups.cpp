#include <iostream>
#include <vector>

using namespace std;
using vvb = vector<vector<int>>;


int main() {
    int t, n;

    scanf("%d", &t);
    vvb scheduleList;
    vector<int> dayCount;

    while (t--) {
        scheduleList.clear();
        dayCount = {0, 0, 0, 0, 0};

        scanf("%d", &n);

        int m = 0, t = 0, w = 0, r = 0, f = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d %d", &m, &t, &w, &r, &f);
            scheduleList.push_back({m, t, w, r, f});
            dayCount[0] += m;
            dayCount[1] += t;
            dayCount[2] += w;
            dayCount[3] += r;
            dayCount[4] += f;
        }

        bool valid = false;

        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int cntA = 0, cntB = 0, intersection = 0;

                for (int k = 0; k < scheduleList.size(); k++) {
                    if (scheduleList[k][i] && scheduleList[k][j]) {
                        intersection++;
                    } else if (scheduleList[k][i]) {
                        cntA++;
                    } else if (scheduleList[k][j]) {
                        cntB++;
                    } else {
                        goto skip;
                    }
                }
                if (dayCount[i] >= n / 2 && dayCount[j] >= n / 2 &&
                    (abs(cntA - cntB) <= intersection)) {
                    valid = true;
                }
                skip:
                continue;
            }
        }
        printf("%s\n", valid ? "YES" : "NO");
    }
}