#include <bits/stdc++.h>
using namespace std;
const int N = 20, M = 1 << N;
int n;
int w[N][N];
int f[M][N]; // 20MB左右

// 状态表示：f[i,j] 表示从起点 0 走到 j，走过的所有点集是二进制i的全部路径；属性：Min
//          e.g. if (i >> k & 1)，说明已经到过点 k 了
// 状态计算：按照到达当前节点j的上个节点k来划分集合：0, 1, .., k, .., n - 1）
// (0 -> ... -> k) -> j: f[i][j] = f[i - (1 << j)][k] + w[k][j]
//          if (i >> j & 1) and (i >> k & 1)
int main() {
  cin >> n;
  for (int i = 0; i < n; i ++ )
    for (int j = 0; j < n; j ++ )
      cin >> w[i][j];

  memset(f, 0x3f, sizeof f);
  f[1 << 0][0] = 0;

  // 内外层for循环不能交换，因为在更新f[i,j]时要保证f[i-(1<<j),k]已更新完毕
  for (int i = 0; i < 1 << n; i ++ )
    for (int j = 0; j < n; j ++ )
      if (i >> j & 1)
        for (int k = 0; k < n; k ++ )
          if (i >> k & 1)
            f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

  cout << f[(1 << n) - 1][n - 1];
  return 0;
}