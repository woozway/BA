#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N]; // 存储每个点的最短路是否已经确定

void dijkstra() { // 稠密图用邻接矩阵 + 朴素dijkstra
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0; // 注意这里还不能st[1]=true

  for (int i = 0; i < n - 1; i ++ ) { // 迭代n-1次即可
    int t = -1; // 取出还未确定最小距离的距离最小的点
    for (int j = 1; j <= n; j ++ )
      if (!st[j] && (t == -1 || dist[t] > dist[j]))
        t = j;

    st[t] = true; // 加入已完成的集合，然后根据dist[t]更新到其他点的最小距离
    for (int j = 1; j <= n; j ++ )
      dist[j] = min(dist[j], dist[t] + g[t][j]);
  }
}

int main() {
  cin >> n >> m;

  memset(g, 0x3f, sizeof g);

  while (m -- ) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x][y] = min(g[x][y], z); // 稠密图需要处理重边（取最小）
  }

  dijkstra();

  if (dist[n] == 0x3f3f3f3f) cout << -1 << endl;
  else cout << dist[n] << endl;
  return 0;
}