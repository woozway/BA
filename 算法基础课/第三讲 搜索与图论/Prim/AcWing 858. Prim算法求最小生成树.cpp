#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool st[N]; // 存储每个点是否已经在生成树中

int prim() { // O(n^2)，稠密图用朴素prim
  memset(dist, 0x3f, sizeof dist);

  int res = 0;
  for (int i = 0; i < n; i++) { // 和dijkstra不一样，prim需要迭代n次
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t==-1 || dist[t]>dist[j]))
        t = j;

    if (i && dist[t]==INF) return INF; // 跳过第一次，都是INF

    if (i) res += dist[t]; // 加入该条到已完成集合的距离最小边
    st[t] = true;

    for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]); // 用t点更新所有其他点到生成树的距离：可能存在负自环，要写在res+=dist[t]更新后
  }
  return res;
}

int main() {
  memset(g, 0x3f, sizeof g);

  cin >> n >> m;

  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = g[v][u] = min(g[u][v], w); // 存储无向图
  }

  int t = prim();

  if (t == INF) puts("impossible");
  else printf("%d\n", t);

  return 0;
}