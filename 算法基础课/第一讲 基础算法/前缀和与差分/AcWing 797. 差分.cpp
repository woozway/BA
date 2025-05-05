#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int d[N];

void insert(int l, int r, int c) {
  d[l] += c, d[r+1] -= c; // 差分核心操作，给a[l~r]范围内的数都+c
}

int main() {
  int n, m;
  cin >> n >> m;

  int a;
  for (int i = 1; i < n+1; i++) {
    scanf("%d", &a); // 也可以额外开个a[]存原始读入值
    insert(i, i, a); // 构建初始差分数组d
  }

  int l, r, c;
  while (m--) {
    scanf("%d%d%d", &l, &r, &c);
    insert(l, r, c);
  }

  for (int i = 1; i < n+1; i++) {
    d[i] += d[i-1]; // 全部差分操作后的结果为d的前缀和
    printf("%d ", d[i]);
  }

  return 0;
}