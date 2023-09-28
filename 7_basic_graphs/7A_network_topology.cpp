#include <iostream>
#include <vector>

using namespace std;

string identifyTopology(vector<int> edges, int n) {
    int d1Edge = 0, d2Edge = 0, starPoint = 0;
    for (int i = 0; i < n; i++)  // count the number of nodes with degree 1
        if (edges[i] == 1) d1Edge++;
        else if (edges[i] == 2) d2Edge++;
        else if (edges[i] == n - 1) starPoint++;
    if (d1Edge == 2 && d2Edge == n - 2)
        return "bus topology";
    else if (d1Edge == n - 1 && starPoint == 1)
        return "star topology";
    else if (d1Edge == 0 && d2Edge == n)
        return "ring topology";
    else
        return "unknown topology";
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    vector<int> edges(n, 0);
    for (int i = 0; i < e; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        edges[n1 - 1]++;
        edges[n2 - 1]++;
    }
    printf("%s\n", identifyTopology(edges, n).c_str());
2}