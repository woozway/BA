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
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);

  for (int i = 1; i <= n; i++) s[i] += s[i-1];

  for (int len = 2; len <= n; len++) // 枚举区间长度；len=1时不需要合并，没有代价
    for (int i = 1; i+len-1 <= n; i++) { // 枚举左端点
      int l = i, r = i + len - 1;
      f[l][r] = 1e8;
      for (int k = l; k < r; k++) // 枚举决策
        f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
    }

  printf("%d\n", f[1][n]);
  return 0;
}