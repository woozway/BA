#include <iostream>
using namespace std;
const int N = 1010;
int v[N], w[N];
// int f[N][N]; // f[i][j]表示：前i件物品总体积不超过j的最大总价值
int f[N]; // f[j]表示：拿了总体积不超过j的物品，最大总价值

//                        / 集合：前i个物品且总体积不超过j的所有选法
//        / 状态表示f[i,j]
// DP问题                 \ 属性：Max, Min, 数量
//        \                            / 不选 f[i-1,j]
//          状态计算：集合的划分（第i个物品）
//                                     \ 选 f[i-1,j-v[i]] + w[i]
int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

  // // 二维写法
  // for (int i = 1; i <= n; i ++ )
  //   for (int j = 0; j <= m; j ++ ) {
  //     f[i][j] = f[i - 1][j];
  //     if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
  //   }
  // cout << f[n][m] << endl;

  // 滚动数组优化：j从大到小更新，因为f[i][j]需要从f[i-1][j]转移来而不是f[i][j]
  for (int i = 1; i <= n; i ++ )
    for (int j = m; j >= v[i]; j -- )
      f[j] = max(f[j], f[j - v[i]] + w[i]);

  cout << f[m] << endl;
  return 0;
}