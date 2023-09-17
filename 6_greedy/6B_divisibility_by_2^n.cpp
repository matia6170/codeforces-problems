#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ull = unsigned long long;
using ll = long long;

ll log2n(ll n){
    ll ans = 0;
    while (n%2 == 0){
        ans++;
        n /= 2;
    }
    return ans;

}

ll calculate2n(vector<ull> &nums) {
    vector<ull> extras;
    ull n = nums.size();
    ull pOfTwo = 0;
    ull extra = 0;

    for (ull i = 1; i <= n; i++) {
        pOfTwo += log2n(nums[i - 1]);
        if (i % 2 == 0) {
            ll e = log2n(i);
            extras.push_back(e);
            extra += e;
        }

    }
    if (pOfTwo >= n) return 0;
    if (pOfTwo + extra < n) return -1;
    ll s = 0;
    sort(extras.rbegin(), extras.rend());
    for (ll i = 0; i < extras.size(); i++) {
        if (pOfTwo >= n) {
            break;
        }

        pOfTwo += extras[i];
        s++;
    }



    return pOfTwo < n ? -1 : s;

}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<ull> nums(n);

        for (int i = 0; i < n; i++) scanf("%llu", &nums[i]);
        printf("%lld\n", calculate2n(nums));
    }

}