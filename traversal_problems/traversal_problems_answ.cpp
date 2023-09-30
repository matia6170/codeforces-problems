#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 30;
int n, p[N], ans;
char str[55];
bool vis[N];
int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) p[fx] = fy;
}
void init() {
    for (int i = 0; i < 26; i++) p[i] = i;
}
int main() {
    init();  // init the union-find set. The set is used to check whether the
             // graph is connected.
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &str);
        int len = strlen(str);
        vis[str[0] - 'a'] = true;
        for (int j = 1; j < len; j++) {
            vis[str[j] - 'a'] = true;
            merge(str[j] - 'a', str[j - 1] - 'a');
        }
    }
    for (int i = 0; i < 26; i++) {
        if (vis[i] && p[i] == i) { // checks if it has been visited. and whether it is the root of the union-find set.
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
