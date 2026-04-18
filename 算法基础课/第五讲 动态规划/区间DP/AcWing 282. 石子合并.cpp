#include <iostream>
using namespace std;
const int N = 310;
int n;
int s[N];
int f[N][N];

//                        / 集合：所有将[i..j]堆石子合并成一堆的合并方式
//        / 状态表示f[i,j]
// DP问题                 \ 属性：Min
//        \ 
//          状态计算：以区间[i,j]中最后一次合并位置来划分集合，分成 [i,k] 和 [k+1,j] 两部分
//            f[i, j] = min(f[i,j], f[i, k] + f[k + 1, j] + sum(i, j)), i <= k < j
//            sum(i, j) 即 s[j] - s[i-1]，表示最后两堆合并时本身的重量代价
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++ ) scanf("%d", &s[i]);

  for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1]; // 前缀和

  for (int len = 2; len <= n; len ++ ) // 枚举区间长度；len=1 时不需要合并
    for (int st = 1; st + len - 1 <= n; st ++ ) { // 枚举区间左端点start
      int i = st, j = st + len - 1;
      f[i][j] = 1e9;
      for (int k = i; k < j; k ++ ) // 枚举分割点k，分成 [i,k] 和 [k+1,j]
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
    }

  printf("%d\n", f[1][n]);
  return 0;
}