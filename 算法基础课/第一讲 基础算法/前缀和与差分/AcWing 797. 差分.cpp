#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int b[N];

// a[1], a[2], ..., a[n]
// b[i] = a[i] - a[i - 1], b[1] = a[1]
// a[i] = b[1] + b[2] + ... + b[i]
//      = a[1] + a[2] - a[1] + ... + a[i] - a[i - 1]
void insert(int l, int r, int c) {
  b[l] += c, b[r + 1] -= c; // 差分核心操作，给a[l~r]范围内的数都+c
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i ++ ) {
    int a;
    scanf("%d", &a); // 也可以额外开个a[]存原始读入值
    insert(i, i, a); // 构建初始差分数组b
  }

  while (m -- ) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    insert(l, r, c);
  }

  for (int i = 1; i <= n; i ++ ) {
    b[i] += b[i - 1]; // 全部差分操作后的结果为b的前缀和
    printf("%d ", b[i]);
  }
  return 0;
}