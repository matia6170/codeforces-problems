#include <stdio.h>

#include <vector>

using namespace std;

using ull = unsigned long long;


int main() {
    int n, q;
    vector<ull> allNotifications;
    vector<vector<ull>> appIdNotifications;

    scanf("%d %d", &n, &q);

    appIdNotifications.resize(n);

    for (int i = 0; i < q; i++) {
        int t, b;

        scanf("%d %d", &t, &b);

        if (t == 1) {
            allNotifications.push_back(b);
            appIdNotifications[b - 1].push_back(b);
        } else if (t == 2) {
            appIdNotifications[b - 1].clear();
            allNotifications.erase(remove(allNotifications.begin(), allNotifications.end(),b));
            
            // int allNotificationsSize =
            //     allNotifications
            //         .size();  // remove notifications from master list
            // // for (int j = 0; j < allNotificationsSize; j++) {
            //     if (allNotifications[j] == b) {
            //         allNotifications.erase(allNotifications.begin() + j - 1);
            //     }
            // }
        } else {  // delete most recent b notifications
            for (int j = 0; j < b; j++) {
                int appId =allNotifications[0];  // save appId to remove from
                                              // coresponding vector later
                allNotifications.erase(allNotifications.begin());  // remove from master list

                appIdNotifications[appId - 1]
                    .pop_back();  // remove noti. from coresponding vector
            }
        }

        int allNotificationsSize = allNotifications.size();
        printf("%d\n", allNotificationsSize);
    }
}