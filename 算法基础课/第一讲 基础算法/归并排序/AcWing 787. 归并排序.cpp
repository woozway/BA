#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N]; // b用作临时中转

void merge_sort(int l, int r) { // 递归处理左右使之有序，然后合并
  if (l >= r) return;

  int mid = l+r >> 1;
  merge_sort(l, mid);
  merge_sort(mid+1, r);

  int i = l, j = mid+1;
  for (int k = l; k <= r; k++)
    if (j>r || (i<=mid && a[i]<=a[j])) b[k] = a[i++]; // 这里写<=才稳定；&&优先级高于||不加括号也可以
    else b[k] = a[j++];

  for (int k = l; k <= r; k++) a[k] = b[k];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  merge_sort(0, n-1);

  for (int i = 0; i < n; i++) printf("%d ", a[i]);

  return 0;
}