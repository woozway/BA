#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2e9;
typedef pair<int, int> pii;
vector<pii> segs, res;

void merge() {
  sort(segs.begin(), segs.end()); // 按左端点排序

  int st = -inf, ed = -inf; // 初始化第0段的start和end为-inf
  for (auto seg: segs)
    if (ed < seg.first) {
      if (st != -inf) res.push_back({st, ed});
      st = seg.first, ed = seg.second;
    }
    else ed = max(ed, seg.second);

  if (st != -inf) res.push_back({st, ed}); // 主要是处理边界问题
}

int main() {
  int n;
  cin >> n;

  int l, r;
  while (n--) {
    scanf("%d%d", &l, &r);
    segs.push_back({l, r});
  }

  merge();

  cout << res.size() << endl;

  return 0;
}