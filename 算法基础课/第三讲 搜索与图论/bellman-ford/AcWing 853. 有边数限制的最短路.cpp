#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 10010;
int dist[N], last[N];
struct Edge {
  int a, b, w;
} edges[M];
int n, m, k;

// 原理：对所有的边进行 k 轮暴力松弛操作，每轮可使用的边数递增（1->k）
// 注意bf更新时有“串联”效应会影响后续松弛操作，所以需使用last备份上一次的dist：
//   假设1->2->3，边权1，因为每轮松弛都要遍历m条边，如使用dist，可能第一轮过后：
//   dist[2]=1, dist[3]=2，这会违背第一轮中只用1条边的原则
void bellman_ford() { // O(nm) 适合稠密图，可处理负权边和判断是否存在负环；求k步内只能用bf
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  while (k -- ) {
    memcpy(last, dist, sizeof last); // 用last备份上一次的dist
    for (int i = 0; i < m; i ++ ) {
      auto e = edges[i];
      dist[e.b] = min(dist[e.b], last[e.a] + e.w); // bf更新过程中遇到负权边e.w时INF会变小一点
    }
  }
}

int main() { // 单源最短路，bf只存边即可
  cin >> n >> m >> k;

  for (int i = 0; i < m; i ++ ) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    edges[i] = {x, y, z};
  }

  bellman_ford();

  if (dist[n] > 0x3f3f3f3f / 2) puts("impossible"); // 因c++中正无穷的表示方式，计算中会导致不同正无穷的值有小差别，比如-100
  else printf("%d\n", dist[n]);
  return 0;
}

// // 另一个版本：
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 510, INF = 0x3f3f3f3f;
// int g[N][N];
// int d[N], last[N];
// int n, m, k;

// void bellman_ford() {
//   memset(d, 0x3f, sizeof d);
//   d[1] = 0;

//   while (k -- ) {
//     memcpy(last, d, sizeof last);
//     for (int i = 1; i <= n; i ++ )
//       for (int j = 1; j <= n; j ++ )
//         if (g[i][j] != INF && d[j] > last[i] + g[i][j])
//           d[j] = last[i] + g[i][j];
//   }
// }

// int main() {
//   cin >> n >> m >> k;

//   memset(g, 0x3f, sizeof g);
//   while (m -- ) {
//     int a, b, c;
//     cin >> a >> b >> c;
//     g[a][b] = min(g[a][b], c);
//   }

//   bellman_ford();
//   if (d[n] > INF / 2) cout << "impossible" << endl;
//   else cout << d[n] << endl;
//   return 0;
// }