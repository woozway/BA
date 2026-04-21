#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Range {
  int l, r;
  bool operator< (const Range &W) const {
    return l < W.l;
  }
} range[N];

// 1. 将所有区间按左端点从小到大排序
// 2. 从前往后依次枚举每个区间，在所有能覆盖 start 的区间中，选择右端点
//    最大的区间，然后将 start 更新成右端点的最大值
// 证：ans = cnt
//    因为算法实现时每次得到的一段区间的右端点 ci 一定 >=ai，可将 ai 替换成 ci，
//    即可以将任何一个最优解调整成当前算法方案，所以 ans 一定和 cnt 相等
int main() {
  int st, ed, n;
  cin >> st >> ed >> n;
  for (int i = 0; i < n; i ++ ) cin >> range[i].l >> range[i].r;

  sort(range, range + n);

  int res = 0;
  bool success = false;
  for (int i = 0; i < n; i ++ ) { // i：当前待处理的“覆盖起点”指针
    int j = i, r = -2e9; // j：扫描“候选人”的探测指针
    while (j < n && range[j].l <= st) {
      r = max(r, range[j].r);
      j ++ ;
    }
    if (r < st) { // r没更新，说明一定有空隙
      res = -1;
      break;
    }

    res ++ ;
    if (r >= ed) { // 提前完成
      success = true;
      break;
    }

    st = r;
    i = j - 1; // 因为for中i++，所以下次循环i会从j开始
  }

  if (!success) res = -1;
  cout << res << endl;
  return 0;
}