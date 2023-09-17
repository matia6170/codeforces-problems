#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool valid(vector<ll> &sums, int n) {
    int k = sums.size();
    if (k == 1) return true;
    vector<ll> v(n);
    int j = n - 1;
    for (int i = k - 1; i >= 1; i--, j--) {
        v[j] = sums[i] - sums[i - 1];
    }
    while (j >= 0) {
        v[j] = v[j + 1];
        sums[0] -= v[j];
        j--;
    }
    v[0] += sums[0];
    return is_sorted(v.begin(), v.end());
}



int main() {
    ll t, n, k;

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &n, &k);
        vector<ll> sums(k, 0);
        for (int i = 0; i < k; i++) scanf("%lld", &sums[i]);
        printf("%s\n", valid(sums, n) ? "YES" : "NO");
    }
}