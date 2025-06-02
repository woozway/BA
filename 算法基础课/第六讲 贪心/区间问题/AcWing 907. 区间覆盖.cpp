#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
struct Range {
  int l, r;
  bool operator< (const Range &W)const {
    return l < W.l;
  }
} range[N];

// 证：ans = cnt
// 因为算法实现时每次得到的一段区间的右端点ci一定大于ai，可以将ai替换成ci，
// 即可以将任何一个最优解调整成当前算法方案，所以ans一定和cnt相等
int main() {
  int st, ed, n;
  cin >> st >> ed >> n;
  for (int i = 0; i < n; i ++ ) {
    int l, r;
    scanf("%d%d", &l, &r);
    range[i] = {l, r};
  }

  // 1. 将所有区间按左端点从小到大排序
  // 2. 从前往后依次枚举每个区间，在所有能覆盖start的区间中，选择右端点
  //    最大的区间，然后将start更新成右端点的最大值
  sort(range, range + n);

  int res = 0;
  bool success = false;
  for (int i = 0; i < n; i ++ ) {
    int j = i, r = -2e9;
    while (j < n && range[j].l <= st) {
      r = max(r, range[j].r);
      j ++ ;
    }

    if (r < st) {
      res = -1;
      break;
    }

    res ++ ;
    if (r >= ed) {
      success = true;
      break;
    }

    st = r;
    i = j - 1;
  }

  if (!success) res = -1;
  cout << res << endl;
  return 0;
}