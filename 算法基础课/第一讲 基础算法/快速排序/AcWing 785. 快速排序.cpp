#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N];

void quick_sort(int l, int r) { // 根据pivot将所有元素分成左右两拨，然后递归左右
  if (l >= r) return; // >=，因为快排中区间内可能没有数

  int x = a[l + r >> 1]; // x直接取a[l]也可，但测试用例增强了
  int i = l - 1, j = r + 1; // i和j初始化在[l,r]之外，后面会先++
  while (i < j) {
    do ++ i; while (a[i] < x);
    do -- j; while (a[j] > x);
    if (i < j) swap(a[i], a[j]);
  }

  quick_sort(l, j); // a[l~j]都<=x
  quick_sort(j + 1, r); // a[j+1~r]都>=x
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  quick_sort(0, n - 1);

  for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);
  return 0;
}