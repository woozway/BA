#include <iostream>
using namespace std;
const int N = 1010;
int v[N], w[N];
// int f[N][N];
int f[N];

//                        / 集合：前i个物品且总体积不超过j的所有选法
//        / 状态表示f[i,j]
// DP问题                 \ 属性：Max, Min, 数量
//        \                            / 不选 f[i-1,j]
//          状态计算：集合的划分（第i个物品）
//                                     \ 选k个 f[i-1,j-v[i]*k] + w[i]*k

// f[i,j]   = Max(f[i-1,j], f[i-1,j-v] + w, f[i-1,j-2v] + 2w, ...)
// f[i,j-v] = Max(          f[i-1,j-v],     f[i-1,j-2v] +  w, ...)
// => f[i,j] = Max(f[i-1,j], f[i,j-v] + w)
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

  // // 朴素TLE
  // for (int i = 1; i <= n; i++)
  //   for (int j = 0; j <= m; j++)
  //     for (int k = 0; v[i]*k <= j; k++)
  //       f[i][j] = max(f[i][j], f[i-1][j - v[i]*k] + w[i]*k);
  // cout << f[n][m] << endl;

  // for (int i = 1; i <= n; i++)
  //   for (int j = 0; j <= m; j++) {
  //     f[i][j] = f[i-1][j];
  //     if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
  //   }
  // cout << f[n][m] << endl;

  // 优化后：和0/1背包的区别是j从小到大更新，因为由f[i,..]转移来而不是f[i-1,..]
  for (int i = 1; i <= n; i++)
    for (int j = v[i]; j <= m; j++)
      f[j] = max(f[j], f[j - v[i]] + w[i]);
  cout << f[m] << endl;

  return 0;
}
