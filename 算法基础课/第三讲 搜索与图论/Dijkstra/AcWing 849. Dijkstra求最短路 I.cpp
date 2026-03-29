#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N]; // 存储每个点的最短路是否已确定

// 找出当前还未加入st的dist[t]最小的节点t，然后用t到其他节点的距离更新dist
void dijkstra() { // m在O(n^2)量级的稠密图：邻接矩阵 + 朴素dijkstra
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0; // 注意这里还不能st[1]=true，否则后面t取不到1这个起点

  for (int i = 0; i < n - 1; i ++ ) { // 迭代n-1次即可，最后一次迭代会把最后一个点的dist更新
    int t = -1;
    for (int j = 1; j <= n; j ++ )
      if (!st[j] && (t == -1 || dist[t] > dist[j]))
        t = j;

    st[t] = true; // 已确定1到t点的最短路，然后根据dist[t]更新到其他点的最小距离
    for (int j = 1; j <= n; j ++ )
      dist[j] = min(dist[j], dist[t] + g[t][j]);
  }
}

int main() { // 单源最短路，仅限非负权边
  memset(g, 0x3f, sizeof g);

  cin >> n >> m;
  while (m -- ) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    g[a][b] = min(g[a][b], w); // 取距离最小的重边，自环不用处理因为relaxation操作时会过滤
  }

  dijkstra();

  if (dist[n] == 0x3f3f3f3f) cout << -1 << endl; // 说明n点图不连通，到不了
  else cout << dist[n] << endl;
  return 0;
}