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

// 证明：假设答案ans，按照贪心策略选择的点个数为cnt
// 证 ans = cnt 即证：ans >= cnt && ans <= cnt
//   1. 因为cnt是一个可行方案，而ans是所有可行方案中最大值，所以ans >= cnt
//   2. 反证：ans表示两两不相交的区间个数，cnt表示每个区间都至少被一个点覆盖
//      若ans > cnt，矛盾；所以ans <= cnt
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

  // 1. 将每个区间按右端点从小到大排序
  // 2. 从前往后依次枚举每个区间
  //    如果当前区间中已经包含点，则直接pass；否则选择当前区间的右端点
  sort(range, range + n);

  int res = 0, ed = -2e9;
  for (int i = 0; i < n; i ++ )
    if (range[i].l > ed) {
      res ++ ;
      ed = range[i].r;
    }

  printf("%d\n", res);
  return 0;
}