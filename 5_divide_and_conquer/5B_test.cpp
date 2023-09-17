#include <iostream>
#include <vector>
 
using namespace std;
using vvb = vector<vector<int>>;
 
int main() {
    int n, wormCnt = 1;
    vector<int> limit;
    vector<int> juicy;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        sum += a;
        limit.push_back(sum);
        
    }
    // for (int i = 0; i < limit.size(); i++){
    //     printf("%d\n", limit[i]);
    // }
 
    int m = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a = 0;
        scanf("%d", &a);
        int j = 0;
        while (a > limit[j]){ 
            j++;
        }
        printf("%d\n", j+1);
    }
 
    
}