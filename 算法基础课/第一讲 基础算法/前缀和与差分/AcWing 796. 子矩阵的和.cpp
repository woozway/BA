#include <iostream>
using namespace std;
const int N = 1010;
int s[N][N]; // s[x][y]覆盖以x,y为右下角的矩阵所有元素

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ ) {
      scanf("%d", &s[i][j]); // 也可以使用额外一个a[][]先存下数据
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }

  int x1, y1, x2, y2;
  while (q -- ) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
  }
  return 0;
}