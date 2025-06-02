#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  // 设货仓在x处，则总距离f(x) = |x1-x| + |x2-x| + ... + |xn-x|
  // 首尾为一组，则f(x) = (|x1-x| + |xn-x|) + (|x2-x| + |xn-1-x|) + ...
  // 因为每组独立，考虑min(|a-x| + |b-x|)，由数轴作图可知在(a,b)区间内即为最小
  // 所以f(x) >= (xn-x1) + (xn-1-x2) + ...，即x在中位数处最小
  sort(a, a + n);

  int res = 0;
  for (int i = 0; i < n; i ++ ) res += abs(a[i] - a[n / 2]);

  printf("%d\n", res);
  return 0;
}