#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  while (q--) {
    int k;
    cin >> k;

    int l = 0, r = n-1;
    while (l < r) {
      int mid = l+r >> 1;
      if (a[mid] >= k) r = mid;
      else l = mid + 1;
    }

    if (a[l] != k) puts("-1 -1");
    else {
      cout << l << ' ';

      l = 0, r = n-1;
      while (l < r) {
        int mid = l+r+1 >> 1;
        if (a[mid] <= k) l = mid; // 这种更新时需要回过头来给l+r+1
        else r = mid - 1;
      }
      cout << l << endl;
    }
  }
  return 0;
}