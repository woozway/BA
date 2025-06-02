#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n, m;
int g[N][N], d[N][N];

void bfs() {
  queue<PII> q;

  memset(d, -1, sizeof d);
  d[1][1] = 0;
  q.push({1, 1});

  int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
  while (q.size()) {
    auto t = q.front(); q.pop();
    for (int i = 0; i < 4; i ++ ) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && !g[x][y] && d[x][y] == -1) {
        d[x][y] = d[t.first][t.second] + 1;
        q.push({x, y});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
      scanf("%d", &g[i][j]);

  bfs();

  cout << d[n][m] << endl;
  return 0;
}