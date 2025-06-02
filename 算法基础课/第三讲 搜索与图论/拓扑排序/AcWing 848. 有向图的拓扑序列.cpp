#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx = 1;
int q[N], hh, tt = -1;
int n, m, d[N]; // d[]存每一个节点的入度

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void topsort() {
  for (int i = 1; i <= n; i ++ )
    if (!d[i]) q[ ++ tt] = i;

  while (hh <= tt) {
    int t = q[hh ++ ];
    for (int i = h[t]; i; i = ne[i]) {
      int j = e[i];
      if (-- d[j] == 0) q[ ++ tt] = j;
    }
  }
}

int main() {
  cin >> n >> m;
  while (m -- ) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    d[y] ++ ;
  }

  topsort();

  if (tt != n - 1) cout << -1 << endl; // 如果每个节点都入队过，那么存在拓扑序，即入队的顺序
  else {
    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);
    puts("");
  }
  return 0;
}