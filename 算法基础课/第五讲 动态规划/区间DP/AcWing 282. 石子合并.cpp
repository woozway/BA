#include <iostream>
using namespace std;
const int N = 310;
int n;
int s[N];
int f[N][N];

//                        / 集合：所有将第i堆到第j堆石子合并成一堆的合并方式
//        / 状态表示f[i,j]
// DP问题                 \ 属性：Min
//        \ 
//          状态计算：集合的划分（以最后一次合并分界线的位置来划分）
//          左边：1,2,...,k-2,k-1个，右边：k-1,k-2,...,2,1个（区间元素个数k = j-i+1）
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++ ) scanf("%d", &s[i]);

  for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];

  for (int len = 2; len <= n; len ++ ) // 枚举区间长度；len=1时不需要合并
    for (int st = 1; st + len - 1 <= n; st ++ ) { // 枚举区间左端点start
      int i = st, j = st + len - 1;
      f[i][j] = 1e9;
      for (int k = i; k < j; k ++ ) // 枚举分割点
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
    }

  printf("%d\n", f[1][n]);
  return 0;
}