#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N], tmp[N];

LL merge_sort(int l, int r) {
  if (l >= r) return 0;

  int mid = l + r >> 1;
  LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

  int i = l, j = mid + 1;
  for (int k = l; k <= r; k ++ )
    if (j > r || i <= mid && a[i] <= a[j]) tmp[k] = a[i ++ ];
    else tmp[k] = a[j ++ ], res += mid - i + 1; // 归并时候a[i~mid]的数都比当前的a[j]要大，加上这些逆序对数

  for (int k = l; k <= r; k ++ ) a[k] = tmp[k];

  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  cout <<  merge_sort(0, n - 1) << endl;
  return 0;
}