#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Range {
  int l, r;
  bool operator< (const Range &W)const {
    return r < W.r;
  }
} range[N];

// 证明：假设目标值ans，按照贪心策略选择的点个数为cnt
// 证 ans = cnt 即证：ans >= cnt && ans <= cnt
//   1. 因为cnt是一个可行方案，而ans是所有可行方案中最小值，所以ans <= cnt
//   2. 因为在极端情况下是会有cnt个两两相互无交集的区间，所以ans >= cnt, Q.E.D.
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &range[i].l, &range[i].r);

  sort(range, range + n); // 每个区间按右端点从小到大排序

  int res = 0, ed = -2e9;
  for (int i = 0; i < n; i++) // 从前往后依次枚举每个区间
    if (range[i].l > ed) { // 若当前区间不覆盖上一区间右端点，则cnt+1，且选中新右端点
      res++;
      ed = range[i].r;
    }

  printf("%d\n", res);
  return 0;
}