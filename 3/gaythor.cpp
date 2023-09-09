#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

using ull = unsigned long long;

void notification(vector<vector<ull>>& unread, unordered_set<ull>& seen,
                  vector<ull>& actions, ull& a_idx, int action, ull x, ull t) {
    if (action == 1) {
        unread[x].push_back(t);
        seen.insert(t);
        actions.push_back(t);
    } else if (action == 2) {
        for (int id : unread[x]) {
            seen.erase(id);
        }
        unread[x].clear();
    } else if (action == 3) {
        while (a_idx < x) {
            seen.erase(actions[a_idx]);
            a_idx++;
        }
    }
    cout << seen.size() << endl;
}
int main() {
    // test();
    ull applications, t, action, x;
    cin >> applications >> t;
    vector<vector<ull>> unread(applications + 1);
    unordered_set<ull> seen;
    vector<ull> actions;
    ull start_q = 0;
    while (t) {
        cin >> action >> x;

        notification(unread, seen, actions, start_q, action, x, t);
        t--;
    }
}