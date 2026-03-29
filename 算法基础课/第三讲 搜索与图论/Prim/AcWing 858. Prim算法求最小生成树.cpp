#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N]; // dist[i]表示节点i到MST的距离
bool st[N]; // 存储每个点是否已经在生成树中
int n, m;

// 关注“点”：从最初点开始遍历n次，逐步添加到已选顶点集合中最近的点，扩展成一颗MST
int prim() { // O(n^2)，稠密图用朴素prim求MST，第一个点i作为根节点，是任意的
  memset(dist, 0x3f, sizeof dist);

  int res = 0;
  for (int i = 0; i < n; i ++ ) { // 和dijkstra不一样，prim需要迭代n次（迭代一次MST中多一个节点）
    int t = -1;
    for (int j = 1; j <= n; j ++ )
      if (!st[j] && (t == -1 || dist[t] > dist[j]))
        t = j;

    if (i && dist[t] == INF) return INF; // 第一次之后如果遇到最小的都是INF，说明不可达

    if (i) res += dist[t]; // 加入该条到已完成集合的距离最小边
    st[t] = true;

    for (int j = 1; j <= n; j ++ )
      dist[j] = min(dist[j], g[t][j]); // 用已加入MST的t点更新所有点到生成树的距离（可能存在负自环，要写在res+=dist[t]更新后）
  }
  return res;
}

int main() {
  memset(g, 0x3f, sizeof g);

  cin >> n >> m;
  while (m -- ) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = g[v][u] = min(g[u][v], w); // 存储无向图
  }

  int t = prim();
  if (t == INF) puts("impossible");
  else printf("%d\n", t);
  return 0;
}