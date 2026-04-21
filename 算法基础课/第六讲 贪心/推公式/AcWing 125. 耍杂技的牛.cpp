#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e4 + 10;
int n;
PII cow[N];

// 按照 w + s 从小到大排序，最大的危险系数一定是最小的
// 1. 贪心得到的答案 >= 最优解（显然）
// 2. 贪心得到的答案 <= 最优解：假设最优解不是按照 w + s 从小到大排序，
//    则存在 w_i + s_i > w_{i+1} + s_{i+1}，两项交换不影响其他项
//                      第 i 位置上的牛                     第 i + 1 位置上的牛
//   交换前危险系数：w_1 + w_2 + .. + w_{i-1} - s_i   w_1 + .. + w_{i-1} + w_i - s_{i+1}
//   交换后危险系数： w_1 + .. + w_{i-1} - s_{i+1}    w_1 + .. + w_{i-1} + w_{i+1} - s_i
// 整理得（-(w_1 + .. + w_{i-1}) + s_i + s_{i+1}）=> 交换完后该两项危险系数中的最大值会严格变小
//   交换前危险系数：     s_{i+1}                         w_i + s_i
//   交换后危险系数：       s_i                        w_{i+1} + s_{i+1}
int main() {
  cin >> n;
  for (int i = 0; i < n; i ++ ) {
    int w, s;
    scanf("%d%d", &w, &s);
    cow[i] = {w + s, w};
  }

  sort(cow, cow + n);

  int res = -2e9, sum = 0;
  for (int i = 0; i < n; i ++ ) {
    int s = cow[i].first - cow[i].second, w = cow[i].second;
    res = max(res, sum - s); // sum 是当前牛上面的总重量，sum - s 就是当前牛的危险系数
    sum += w;
  }

  cout << res << endl;
  return 0;
}