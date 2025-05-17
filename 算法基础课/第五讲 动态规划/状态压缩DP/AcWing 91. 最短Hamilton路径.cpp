#include <iostream>
#include <cstring>
using namespace std;
const int N = 20, M = 1 << N;
int n;
int w[N][N];
int f[M][N];

//                       / 集合：从0走到j，走过的所有点是i的二进制表示的所有路径
//       / 状态表示f[i,j]
// DP问题                \ 属性：Min
//       \ 
//         状态计算：集合的划分（按照倒数第二个点分类：0, 1, .., k, .., n-1）
//         (0 -> ... -> k) -> j: f[i][j] = f[i - (1<<j)][k] + w[k][j]
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> w[i][j];

  memset(f, 0x3f, sizeof f);
  f[1][0] = 0;

  for (int i = 0; i < 1<<n; i++)
    for (int j = 0; j < n; j++)
      if (i>>j & 1)
        for (int k = 0; k < n; k++)
          if (i>>k & 1)
            f[i][j] = min(f[i][j], f[i - (1<<j)][k] + w[k][j]);

  cout << f[(1<<n) - 1][n-1];
  return 0;
}