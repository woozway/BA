#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Range {
  int l, r;
  bool operator< (const Range &W) const {
    return r < W.r;
  }
} range[N];
int n;

// 1. 将每个区间按右端点从小到大排序
// 2. 从前往后依次枚举每个区间
//   如果当前区间中已经包含点，则直接跳过；否则选择当前区间的右端点
// 证明：假设 ans 是最优解（点数最小值），cnt 是贪心算法得到的方案数
// 证 ans = cnt 即证：ans >= cnt && ans <= cnt
//   1. 因为 cnt 是一个可行方案，而 ans 是所有可行方案中最小值，所以 ans <= cnt
//   2. 因为在极端情况下是会有 cnt 个两两相互无交集的区间，所以 ans >= cnt, QED
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

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