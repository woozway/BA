#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], res;

void quick_select(int l, int r, int k) { // O(n)
  if (l >= r) { // >=或==，因为这里保证区间内一定有数
    res = a[l];
    return;
  }

  int x = a[l+r >> 1];
  int i = l-1, j = r+1;
  while (i < j) {
    do i++; while (a[i] < x);
    do j--; while (a[j] > x);
    if (i < j) swap(a[i], a[j]);
  }

  int sl = j - l + 1; // 得到[l~r]中<=x的个数sl，然后根据sl和k的关系继续在一半里找
  if (sl >= k) quick_select(l, j, k);
  else quick_select(j+1, r, k-sl);
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  quick_select(0, n-1, k);

  cout << res << endl;

  return 0;
}