#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

using ull = unsigned long long;
using v = vector<ull>;

ull cd(v&& distances, size_t k) {
	if (distances.empty()) return 0;
	sort(distances.rbegin(), distances.rend());
	ull distance = 0;
	for (auto i = 0; i < distances.size(); i += k) {
		distance += 2 * distances[i];
	}
	return distance;
}

ull cd(v& l, v&& r, size_t k) {
	auto l_distance = cd(forward<v>(l), k);
	auto r_distance = cd(forward<v>(r), k);
	auto l_first = l.empty() ? numeric_limits<ull>::min() : l[0];
	auto r_first = r.empty() ? numeric_limits<ull>::min() : r[0];
	return l_distance + r_distance - max(l_first, r_first);
}

int main() {
    ull t, n;
    int tmp;
    size_t k;
    scanf("%llu", &t);

    while (t--) {
        cin >> n >> k;
        vector<ull> rds;
        vector<ull> lds;

        for (ull i = 0; i < n; i++) {
            cin >> tmp;

            if (tmp < 0) {
                lds.push_back(-tmp);
            } else {
                rds.push_back(tmp);
            }
        }

        ull distance = cd(lds, rds, k);
        printf("%llu\n", distance);
    }

    return 0;
}
