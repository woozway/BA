#include <iostream>
using namespace std;
const int N = 510, INF = 1e9;
int n;
int a[N][N];
int f[N][N];

// 1. 状态表示f[i,j]：到达i,j位置的路径和；属性：Max
// 2. 状态计算：集合划分按经过下方哪个位置：f[i,j] = max(f[i-1,j-1], f[i-1,j]) + a[i,j]
int main() {
  cin >> n;
  for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= i; j ++ )
      cin >> a[i][j];

  for (int i = 0; i <= n; i ++ )
    for (int j = 0; j <= i + 1; j ++ )
      f[i][j] = -INF;

  f[1][1] = a[1][1];
  for (int i = 2; i <= n; i ++ )
    for (int j = 1; j <= i; j ++ )
      f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];

  int res = -INF;
  for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
  cout << res << endl;

  return 0;
}