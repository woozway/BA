#include <bits/stdc++.h>
using namespace std;
const int N = 20; // 20 > (n-1)*2+1，会有这么多不同的斜边
char g[N][N];
bool col[N], dg[N], adg[N]; // y=x+b, y=-x+b => b=y-x, b=y+x，防止出现负数下标可+n
int n;

void dfs(int u) { // u按行推进
  if (u == n) {
    for (int i = 0; i < n; i ++ ) puts(g[i]);
    puts("");
    return;
  }

  for (int i = 0; i < n; i ++ )
    if (!col[i] && !dg[i - u + n] && !adg[u + i]) { // 当前列，主对角线，反对角线都不在攻击范围；这里不能用((u-i)%n+n)%n，会少计算斜边数
      g[u][i] = 'Q';
      col[i] = dg[i - u + n] = adg[u + i] = true;
      dfs(u + 1);
      col[i] = dg[i - u + n] = adg[u + i] = false;
      g[u][i] = '.';
    }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i ++ )
    for (int j = 0; j < n; j ++ )
      g[i][j] = '.';

  dfs(0);

  return 0;
}