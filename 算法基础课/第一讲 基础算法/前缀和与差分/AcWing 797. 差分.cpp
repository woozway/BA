#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m, b[N];

// 有原数组a：a[1], a[2], ..., a[n]
// 构建数组b：b[1] = a[1], b[i] = a[i] - a[i - 1], i > 1
// => a[i] = b[1] + b[2] + ... + b[i]
//         = a[1] + (a[2] - a[1]) + ... + (a[i] - a[i - 1])
// 即b[1~i]的前缀和为a[i]，差分将对于a中某个区间[l,r]的操作转化为b中两个端点的操作
// 可类比为一排电灯泡，b[l] + c 表示将从 l 开始往后的电灯泡亮度 + c
// 过程中对b数组施加的一系列操作，最后可以通过求其前缀和数组还原为数组a中最后的结果
void insert(int l, int r, int c) {
  b[l] += c, b[r + 1] -= c; // 差分核心操作，给a[l~r]范围内的数都+c
}

int main() {
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