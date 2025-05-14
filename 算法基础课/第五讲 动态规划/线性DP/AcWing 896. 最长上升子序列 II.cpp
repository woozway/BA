#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N], q[N]; // q[i]表示长度为1的LIS的最小结尾数字；若j<i,则q[j]<q[i]

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int len = 0;
  for (int i = 0; i < n; i++) {
    int l = 0, r = len;
    while (l < r) { // 二分来查找那个最大的小于a[i]的数
      int mid = l + r + 1 >> 1;
      if (q[mid] < a[i]) l = mid;
      else r = mid - 1;
    }
    len = max(len, r + 1);
    q[r + 1] = a[i];
  }
  printf("%d\n", len);

  return 0;
}