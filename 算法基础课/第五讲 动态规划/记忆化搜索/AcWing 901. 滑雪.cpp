#include <cstring>
#include <iostream>
using namespace std;
const int N = 310;
int n, m;
int g[N][N];
int f[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y) {
  int &v = f[x][y];
  if (v != -1) return v;

  v = 1;
  for (int i = 0; i < 4; i ++ ) {
    int a = x + dx[i], b = y + dy[i];
    if (a >= 0 && a < n && b >= 0 && b < m && g[x][y] > g[a][b])
      v = max(v, dp(a, b) + 1);
  }
  return v;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i ++ )
    for (int j = 0; j < m; j ++ )
      scanf("%d", &g[i][j]);

  memset(f, -1, sizeof f);

  int res = 0;
  for (int i = 0; i < n; i ++ )
    for (int j = 0; j < m; j ++ )
      res = max(res, dp(i, j)); // [i,j]位置开始的最远滑雪长度

  printf("%d\n", res);
  return 0;
}