#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 10010;
int n, m, k;
int dist[N], last[N]; // 因为有“串联效应”，需要用last备份上一次的dist
struct Edge {
  int a, b, w;
} edges[M];

void bellman_ford() { // O(nm)适合稠密图：可以处理负权边和判断是否存在负环；求k步内只能用bf
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  while (k--) {
    memcpy(last, dist, sizeof last);
    for (int j = 0; j < m; j++) {
      auto e = edges[j];
      dist[e.b] = min(dist[e.b], last[e.a] + e.w);
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    edges[i] = {x, y, z};
  }

  bellman_ford();

  if (dist[n] > 0x3f3f3f3f/2) puts("impossible"); // 因为正无穷的表示方式，在bf计算中会导致不同正无穷的值有差别，比如-100
  else printf("%d\n", dist[n]);
  return 0;
}