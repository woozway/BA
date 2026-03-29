#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], cnt; // cnt表示heap中元素总个数，下标从1开始（这样i/2就是父节点，左/右子节点分别是i*2和i*2+1）
int n, m;

void down(int u) {
  int t = u;
  if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
  if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
  if (t != u) {
    swap(h[t], h[u]);
    down(t);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
  cnt = n;

  // T = Σ (2^k × (h - k))，k = 0 到 h - 1, k是层数, h是堆的高度log2(n)
  for (int i = n / 2; i; i -- ) down(i); // O(n)建堆：从节点n/2到1

  while (m -- ) {
    printf("%d ", h[1]);
    swap(h[1], h[cnt -- ]);
    down(1);
  }
  return 0;
}