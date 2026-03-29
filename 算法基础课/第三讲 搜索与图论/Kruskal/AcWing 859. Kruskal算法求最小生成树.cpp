#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = N * 2, INF = 0x3f3f3f3f;
int n, m;
int p[N];
struct Edge {
  int a, b, w;
  bool operator< (const Edge &e) const {
    return w < e.w;
  }
} edges[M];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

// 关注“边”：按边权从小到大依次考虑每条边，只要加入该边不形成环，就将其纳入MST
int kruskal() { // O(mlgn) 适合稀疏图；和bf算法一样也只要存edge
  sort(edges, edges + m);

  for (int i = 1; i <= n; i ++ ) p[i] = i;

  int res = 0, cnt = 0;
  for (int i = 0; i < m; i ++ ) {
    int a = edges[i].a, b = edges[i].b, w = edges[i].w;

    a = find(a), b = find(b);
    if (a != b) {
      p[a] = b;
      res += w;
      cnt ++ ;
    }
  }

  if (cnt != n - 1) return INF; // 不到n-1条边，无法成MST
  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i ++ ) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edges[i] = {u, v, w};
  }

  int t = kruskal();
  if (t == INF) puts("impossible");
  else printf("%d\n", t);
  return 0;
}