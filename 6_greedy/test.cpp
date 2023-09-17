#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

unsigned long long calculateDistance(vector<unsigned long long>&& ds,
                                     size_t k) {
    if (ds.empty()) return 0;
    sort(ds.rbegin(), ds.rend());
    unsigned long long d = 0;
    for (auto i = 0; i < ds.size(); i += k) {
        d += 2 * ds[i];
    }
    return d;
}

unsigned long long calculateDistance(vector<unsigned long long>&& l,
                                     vector<unsigned long long>&& r, size_t k) {
    unsigned long long ld =
        calculateDistance(forward<vector<unsigned long long>>(l), k);
    unsigned long long rd =
        calculateDistance(forward<vector<unsigned long long>>(r), k);
    unsigned long long lf =
        l.empty() ? numeric_limits<unsigned long long>::min() : l[0];
    unsigned long long rf =
        r.empty() ? numeric_limits<unsigned long long>::min() : r[0];
    return ld + rd - max(lf, rf);
}

int main() {
    unsigned long long t, n;
    int tmp;
    size_t k;
    scanf("%llu", &t);
    while (t) {
        t--;
        cin >> n >> k;
        vector<unsigned long long> rds;
        vector<unsigned long long> lds;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (tmp < 0)
                rds.push_back(-tmp);
            else
                lds.push_back(tmp);
        }
        unsigned long long distance =
            calculateDistance(move(lds), move(rds), k);
        printf("%llu\n", distance);
    }
}