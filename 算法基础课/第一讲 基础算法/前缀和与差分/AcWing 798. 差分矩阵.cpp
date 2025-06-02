#include <iostream>
using namespace std;
const int N = 1010;
int d[N][N]; // d[x][y]覆盖以x,y为左上角的矩阵中所有元素

void insert(int x1, int y1, int x2, int y2, int c) {
  d[x1][y1] += c;
  d[x1][y2 + 1] -= c;
  d[x2 + 1][y1] -= c;
  d[x2 + 1][y2 + 1] += c;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  int a;
  for (int i = 1; i < n + 1; i ++ )
    for (int j = 1; j < m + 1; j ++ ) {
      scanf("%d", &a); // 也可以额外开个a[][]存原始读入值
      insert(i, j, i, j, a);
    }

  int x1, y1, x2, y2, c;
  while (q -- ) {
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
    insert(x1, y1, x2, y2, c);
  }

  for (int i = 1; i < n + 1; i ++ ) {
    for (int j = 1; j < m + 1; j ++ ) {
      d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
      printf("%d ", d[i][j]); // d的前缀和矩阵就是所有操作后获得的数组
    }
    puts("");
  }
  return 0;
}