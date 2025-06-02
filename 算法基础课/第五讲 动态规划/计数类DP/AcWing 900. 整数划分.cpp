#include <iostream>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int n;
int a[N];
// int f[N][N];
int f[N];

//                       / 集合：从1~i中选，总体积恰好为j的方案数
//       / 状态表示f[i,j]
// DP问题                \ 属性：数量
//       \ 
//         状态计算：集合的划分（以最后一个物品（第i个）选择个数来划分0,1,2,..,s个），类似完全背包
//          0: f[i-1,j], 1: f[i-1,j-i], 2: f[i-1,j-i*2], ..., s: f[i-1,j-i*s]

// f[i,j] = f[i-1,j] + f[i-1,j-i] + f[i-1,j-i*2] + ... + f[i-1,j-i*s]
// f[i,j-i] =          f[i-1,j-i] + f[i-1,j-i*2] + ... + f[i-1,j-i*s]
// => f[i,j] = f[i-1,j] + f[i,j-i]
// => f[j] = f[j] + f[j-i] (j从i~n, 滚动数组优化后)
int main() {
  cin >> n;

  // f[0][0] = 1;
  // for (int i = 1; i <= n; i ++ )
  //   for (int j = 0; j <= n; j ++ ) {
  //     f[i][j] = f[i - 1][j];
  //     if (j >= i) f[i][j] = (f[i][j] + f[i][j - i]) % mod;
  //   }
  // cout << f[n][n] << endl;

  // 滚动数组优化
  f[0] = 1;
  for (int i = 1; i <= n; i ++ )
    for (int j = i; j <= n; j ++ )
      f[j] = (f[j] + f[j - i]) % mod;

  cout << f[n] << endl;
  return 0;
}