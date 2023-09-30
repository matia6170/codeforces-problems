#include <iostream>
#include <vector>

using namespace std;

string identifyTopology (vector<int> edges, int n) {
    int count = 0;
    for(int i = 0 ; i < n ; i++) { // count the number of nodes with degree 1
        if(edges[i] == 1) count++;
    }
    if(count == 2) return "bus topology";
    else if(count == n-1) return "star topology";
    else if(count == 0) return "ring topology";
    else return "unknown topology";
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    vector<int> edges(n+1);
    for(int i = 0 ; i < e ; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        edges[n1]++;
        edges[n2]++;
    }
    printf("%s\n",identifyTopology(edges, n).c_str());

    
}