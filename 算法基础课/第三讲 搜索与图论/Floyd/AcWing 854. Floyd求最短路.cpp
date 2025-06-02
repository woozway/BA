#include <iostream>
using namespace std;
const int N = 210, INF = 0x3f3f3f3f;
int n, m, k;
int d[N][N];

void floyd() { // 多源汇问题floyd：可以处理负权边，无法处理负环
  for (int k = 1; k <= n; k ++ )
    for (int i = 1; i <= n; i ++ )
      for (int j = 1; j <= n; j ++ )
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= n; j ++ )
      if (i == j) d[i][j] = 0; // floyd算法需要处理自环
      else d[i][j] = INF;

  while (m -- ) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    d[x][y] = min(d[x][y], z); // 处理重边，取最小
  }

  floyd();

  while (k -- ) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (d[x][y] > INF / 2) puts("impossible"); // 和bellman_ford算法一样，INF可能互相有一些数值差异
    else printf("%d\n", d[x][y]);
  }
  return 0;
}