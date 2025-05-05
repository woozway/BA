#include <iostream>
using namespace std;
const int N = 20; // 20 > (n-1)*2+1，会有这么多不同的斜边
char g[N][N];
bool col[N], dg[N], adg[N]; // y=x+b, y=-x+b => b=y-x, b=y+x，为防止负下标+n
int n;

void dfs(int u) {
  if (u == n) {
    for (int i = 0; i < n; i++) puts(g[i]);
    puts("");
    return;
  }
  for (int i = 0; i < n; i++)
    if (!col[i] && !dg[u+i] && !adg[u-i+n]) { // 当前列，对角线，反对角线都不在攻击范围；这里不能用((u-i)%n+n)%n，会少计算斜边数
      g[u][i] = 'Q';
      col[i] = dg[u+i] = adg[u-i+n] = true;
      dfs(u + 1);
      col[i] = dg[u+i] = adg[u-i+n] = false;
      g[u][i] = '.';
    }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      g[i][j] = '.';

  dfs(0);

  return 0;
}