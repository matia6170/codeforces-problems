#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;
const int MAXN = 200010;
const int MAXLOG = 20;
int n, m;
struct Edge {
    int u, v, w, id;
};
Edge map[MAXN];
int cmp(const Edge a, const Edge b) { return a.w < b.w; }
int cmp1(const Edge a, const Edge b) { return a.id < b.id; }
struct edge {
    int next, to, val;
};
edge e[MAXN * 2];

int head[MAXN], cnt;
void addedge(int u, int v, int w) {
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].val = w;
    head[u] = cnt;
}
int fa[MAXN];
int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
long long ans;
bool use[MAXN];
void Kruskal() {
    sort(map + 1, map + 1 + m, cmp);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= m; i++) {
    int f1=find (map[i].u), f2=find(map[i].v);
    if (f1 == f2) {
        continue;
    }
    fa[f1] = f2;
    use[map[i].id] = true;
    ans += map[i].w;
    addedge(map[i].u, map[i].v, map[i].w);
    addedge(map[i].v, map[i].u, map[i].w);
    }
}
int f[MAXN][MAXLOG], g[MAXN][MAXLOG];
int deep[MAXN];
bool visit[MAXN];
void dfs(int u) {
    visit[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (visit[v]) {
        continue;
    }
    deep[v] = deep[u] + 1;
    f[v][0] = u;
    g[v][0] = e[i].val;
    dfs(v);
    }
}
void build() {
    for (int j = 1; j < MAXLOG; j++) {
    for (int i = 1; i <= n; i++) {
        f[i][j] = f[f[i][j - 1]][j - 1];
        g[i][j] = max(g[i][j - 1], g[f[i][j - 1]][j - 1]);
    }
    }
}
int maxx;
void go_up(int &x, int d){
    for (int i=0; i<MAXLOG; i++){
        if (d & (1<<i)){
            maxx = max(maxx, g[x][i]);
            x = f[x][i];
        }
    }
}
void LCA(int x, int y){
    if(deep[x]>deep[y]){
        go_up(x, deep[x]-deep[y]);
    }else{
        go_up(y, deep[y]-deep[x]);
    }
    if (x==y){
        return;
    }
    for (int i = MAXLOG-1; i>=0; i--){
        if (f[x][i]!=f[y][i]){
            maxx = max(maxx, max(g[x][i], g[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    maxx = max(maxx, max(g[x][0], g[y][0]));
    return;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++){
        scanf("%d%d%d", &map[i].u, &map[i].v, &map[i].w);
        map[i].id = i;
    }
    Kruskal();
    deep[1]=1;
    dfs(1);
    build();
    sort(map+1, map+1+m, cmp1);
    for(int i = 1; i<=m; i++){
        if (use[i]){
            printf("%lld\n", ans);
        }else{
            maxx = 0;
            LCA(map[i].u, map[i].v);
            printf("%lld\n", ans-maxx+map[i].w);
        }
    }
}