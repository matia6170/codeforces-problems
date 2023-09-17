#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll isKillable(vector<ll> const& attack_times, ll k, ll h) {
    for (size_t i = 0; i < attack_times.size() - 1; i++) {
        h -= min(attack_times[i] + k, attack_times[i + 1]) - attack_times[i];
    }
    h -= k;
    return h;
}

ll calculateKMin(vector<ll>& attack_times, ll h) {
    ll len = 1;
    ll r = h;
    ll k;
    ll min_diff = numeric_limits<ll>::min();
    while (len <= r) {
        ll m = (len + r) / 2;
        ll result = isKillable(attack_times, m, h);

        if (result < 0) {
            if (result > min_diff) {
                k = m;
                min_diff = result;
            }
            r = m - 1;
        } else if (result > 0) {
            len = m + 1;
        } else
            return m;      }
    return k;
}

int main() {
    int t, n;
    ll h;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %lld", &n, &h);
        vector<ll> at(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &at[i]);
        }

        printf("%lld\n", calculateKMin(at, h));
    }
}
