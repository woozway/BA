#include <iostream>
using namespace std;
const int N = 100010;
int n, k, a[N];

// O(n)，几何级数 n + n/2 + n/4 + n/8 + ... = 2n
int quick_select(int l, int r, int k) {
  if (l >= r) return a[l]; // >=或==，因为这里保证区间内一定有数

  int x = a[l + r >> 1];
  int i = l - 1, j = r + 1;
  while (i < j) {
    do i ++ ; while (a[i] < x);
    do j -- ; while (a[j] > x);
    if (i < j) swap(a[i], a[j]);
  }

  int sl = j - l + 1; // 得到[l~r]中<=x的个数sl，然后根据sl和k的关系继续在一半里找
  if (sl >= k) return quick_select(l, j, k);
  else return quick_select(j + 1, r, k - sl);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

  cout << quick_select(1, n, k) << endl;

  return 0;
}