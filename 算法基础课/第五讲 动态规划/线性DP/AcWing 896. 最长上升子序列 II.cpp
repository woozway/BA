#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int q[N]; // q[i]表示长度为i的LIS的最小结尾数字；若j<i，则一定q[j]<q[i]（反证法）

// 核心思想（贪心）：如果要让上升子序列尽可能长，那么序列结尾的数字越小越好
int main() {
  cin >> n;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  q[0] = -2e9; // 哨兵保证 q[0] 永远小于序列中的任何数，这里没有也行
  int len = 0;
  for (int i = 0; i < n; i ++ ) {
    int l = 0, r = len;
    while (l < r) { // 二分找q[]中小于a[i]的最大的数p，分成(...<ai), (>=ai...)两部分
      int mid = l + r + 1 >> 1;
      if (q[mid] < a[i]) l = mid;
      else r = mid - 1;
    }
    q[r + 1] = a[i];
    len = max(len, r + 1); // 更新len并在下一位置上放置新数
  }
  printf("%d\n", len);

  return 0;
}