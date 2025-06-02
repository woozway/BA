#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], cnt; // cnt表示heap中元素的总个数

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
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
  cnt = n;

  for (int i = n / 2; i; i -- ) down(i); // O(n)建堆

  while (m -- ) {
    printf("%d ", h[1]);
    swap(h[1], h[cnt -- ]);
    down(1);
  }
  return 0;
}