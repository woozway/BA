#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

// 1. 状态表示：a. f[i,j]集合：字符串a[1~i]变成b[1~j]的最短编辑距离；b. 属性：Min
// 2. 状态计算：集合划分（是否包含a[i], b[j]）；也可以按照增、删、替换3种操作来划分
//    00: f[i-1,j-1]+2, 01: f[i-1,j]+1, 
//    10: f[i,j-1]+1, 11: f[i-1,j-1] if a[i]==b[j] else f[i-1,j-1]+1
int main() {
  scanf("%d%s", &n, a + 1);
  scanf("%d%s", &m, b + 1);

  for (int i = 0; i <= m; i ++ ) f[0][i] = i;
  for (int i = 0; i <= n; i ++ ) f[i][0] = i;

  for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ ) {
      f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
      if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
    }

  printf("%d\n", f[n][m]);

  return 0;
}