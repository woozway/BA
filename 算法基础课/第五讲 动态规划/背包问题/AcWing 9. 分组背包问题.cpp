#include <iostream>
using namespace std;
const int N = 110;
int v[N][N], w[N][N], s[N];
int f[N];

//                        / 集合：前i组物品中选，且总体积不超过j的所有选法
//        / 状态表示f[i,j]
// DP问题                 \ 属性：Max, Min, 数量
//        \                           / 不选 f[i-1,j]
//          状态计算：集合的划分（第i组中）
//                                    \ 选第i组中第k个 f[i-1,j-v[i,k]] + w[i,k]
int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 1; j <= s[i]; j++)
      cin >> v[i][j] >> w[i][j];
  }

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--)
      for (int k = 0; k <= s[i]; k++)
        if (j >= v[i][k])
          f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

  cout << f[m] << endl;
  return 0;
}