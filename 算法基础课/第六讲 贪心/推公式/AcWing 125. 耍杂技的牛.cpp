#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int N = 5e4 + 10;
int n;
pii cow[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int w, s;
    scanf("%d%d", &w, &s);
    cow[i] = {w + s, w};
  }

  // 按照w+s从小到大排序，最大的危险系数一定是最小的
  // 证：贪心得到的答案 >= 最优解（显然）
  //     贪心得到的答案 <= 最优解：假设最优解不是按照w+s从小到大排序，
  //     则存在wi+si > w(i+1) + s(i+1)，两项交换不影响其他项
  //                      第i位置上的牛            第i+1位置上的牛
  //   交换前危险系数： w1+w2+...+w(i-1)-si     w1+...+w(i-1)+wi-s(i+1)
  //   交换后危险系数： w1+...+w(i-1)-s(i+1)    w1+...+w(i-1)+w(i+1)-si
  // 整理得 => 交换完后该两项危险系数中的最大值会严格变小
  //   交换前危险系数：     s(i+1)                   wi + si
  //   交换前危险系数：       si                  w(i+1) + s(i+1)
  sort(cow, cow + n);

  int res = -2e9, sum = 0;
  for (int i = 0; i < n; i++) {
    int s = cow[i].first - cow[i].second, w = cow[i].second;
    res = max(res, sum - s);
    sum += w;
  }

  printf("%d\n", res);
  return 0;
}