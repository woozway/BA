#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
struct Range {
  int l, r;
  bool operator< (const Range &W)const {
    return l < W.l;
  }
} range[N];

// 证明：假设答案ans，按照贪心策略选择的点个数为cnt
// 证 ans = cnt 即证：ans >= cnt && ans <= cnt
//   1. 因为cnt是一个可行方案，而ans是所有可行方案中最小值，所以ans <= cnt
//   2. 假设已有cnt-1个组，当前区间左端点L[i]和以上任一个组的Max_r所在的区间都存在：
//      l <= L[i] <= Max_r，即cnt个区间有公共点L[i],
//      此时合法方案ans为了覆盖cnt个两两互不相交的区间需保证ans >= cnt
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    range[i] = {l, r};
  }

  sort(range, range + n);

  priority_queue<int, vector<int>, greater<int>> heap;
  for (int i = 0; i < n; i++) {
    auto r = range[i];
    if (heap.empty() || heap.top() >= r.l) heap.push(r.r);
    else {
      heap.pop();
      heap.push(r.r);
    }
  }

  cout << heap.size() << endl;
  return 0;
}