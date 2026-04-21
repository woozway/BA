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

// “最大不相交区间数量” 问题与 “区间选点问题” 在数学上是等价的（对偶性）
// 算法步骤：
// 1. 将每个区间按右端点从小到大排序
// 2. 从前往后依次枚举每个区间：
//    如果当前区间的左端点 <= 当前维护的右端点边界（说明重叠），则直接跳过；
//    否则，选中该区间，并以该区间的右端点作为新的边界（相当于在这里放了一个点）
//
// 证明：假设最优解（真正的最大不相交区间数量）为 ans，贪心算法选出的数量为 cnt
// 证 ans = cnt，即证：ans >= cnt 且 ans <= cnt
//    1. 证 ans >= cnt：
//       因为贪心算法实际选出的这 cnt 个区间确实是两两不相交的，这是一个合法的可行解
//       而 ans 是所有可行解中的最大值，所以 ans >= cnt
//    2. 证 ans <= cnt（反证法）：
//       贪心算法的执行过程保证了：我们用选出的这 cnt 个区间的右端点（即 cnt 个点），覆盖了所有的区间
//       假设 ans > cnt，意味着原集合中存在超过 cnt 个两两互不相交的区间
//       既然它们互不相交，要把它们全部覆盖，至少需要 ans 个点
//       这与“我们仅用 cnt 个点就覆盖了所有区间”相矛盾（鸽笼原理）
//       因此，ans <= cnt
int main() {
  cin >> n;
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