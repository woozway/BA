#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
typedef pair<int, int> PII;
vector<PII> segs, res;

void merge() {
  sort(segs.begin(), segs.end()); // 按左端点排序

  int st = -INF, ed = -INF; // 初始化第0段的start和end为-INF
  for (auto seg : segs)
    if (ed < seg.first) {
      if (st != -INF) res.push_back({st, ed}); // 防止加入第0段
      st = seg.first, ed = seg.second;
    }
    else ed = max(ed, seg.second);

  if (st != -INF) res.push_back({st, ed}); // 处理边界（如果总共只有一段时）
}

int main() {
  int n;
  cin >> n;

  int l, r;
  while (n -- ) {
    scanf("%d%d", &l, &r);
    segs.push_back({l, r});
  }

  merge();
  cout << res.size() << endl;
  return 0;
}