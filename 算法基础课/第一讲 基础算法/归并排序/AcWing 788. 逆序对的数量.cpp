#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N];
long long res;

void merge_sort(int l, int r) {
  if (l >= r) return;

  int mid = l + r >> 1;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);

  int i = l, j = mid + 1;
  for (int k = l; k <= r; k ++ )
    if (j > r || i <= mid && a[i] <= a[j]) b[k] = a[i ++ ];
    else b[k] = a[j ++ ], res += mid - i + 1; // 归并时候发现a[i~mid]的数都比当前的a[j]要大，加上这些逆序对数

  for (int k = l; k <= r; k ++ ) a[k] = b[k];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  merge_sort(0, n - 1);

  cout << res << endl;
  return 0;
}