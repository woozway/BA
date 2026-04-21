#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];

// 设货仓在 x 处，则总距离 f(x) = |x_1 - x| + |x_2 - x| + ... + |x_n - x|
// 首尾为一组，则 f(x) = (|x_1 - x| + |x_n - x|) + (|x_2 - x| + |x_{n-1} - x|) + ...
// 因为每组独立，考虑 min(|a - x| + |b - x|)，由数轴作图可知在 (a, b) 区间内即为最小
// 所以 f(x) >= (x_n - x_1) + (x_{n-1} - x_2) + ...，即 x 在中位数处最小
int main() {
  cin >> n;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  sort(a, a + n);

  int res = 0; // 奇数取 a[n / 2]，偶数 [a[n / 2] ~ a[n / 2 + 1]] 都可以
  for (int i = 0; i < n; i ++ ) res += abs(a[i] - a[n / 2]);

  printf("%d\n", res);
  return 0;
}