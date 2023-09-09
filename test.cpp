#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()

{
    int t;

    cin >> t;

    while (t--) {
        LL hc, dc, hm, dm, k, w, a;

        cin >> hc >> dc;

        cin >> hm >> dm;

        cin >> k >> w >> a;

        int i = 0;

        for (i = 0; i <= k; i++) {
            LL midhc = hc + i * a;

            LL middc = dc + (k - i) * w;

            LL col1 = midhc / dm;

            if (midhc % dm != 0) col1++;

            LL col2 = hm / middc;

            if (hm % middc) col2++;

            if (col1 >= col2) break;
        }

        if (i == k + 1)
            cout << "NO";

        else
            cout << "YES";

        if (t) cout << endl;
    }

    return 0;
}