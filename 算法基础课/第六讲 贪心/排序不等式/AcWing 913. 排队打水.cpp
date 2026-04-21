#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n;
int t[N];

// 总时间 = t_1*(n-1) + t_2*(n-2) + ... + t_{n-1}*1 + t_n*0
// 直觉：短作业优先 SJF，将 n 个数从小打到排序，然后贪心
// 证明（调整法）：假设最优答案不是非递减序列，则必存在逆序对：t_i > t_{i+1}
// 交换的两项对其他项无影响，此时总时间为
//   前：t_i*(n-i) + t_{i+1}*(n-i-1)，后：t_{i+1}*(n-i) + t_i*(n-i-1)，
//   前-后：t_i - t_{i+1} > 0，说明可以更优，与假设矛盾，得证
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++ ) scanf("%d", &t[i]);

  sort(t, t + n);

  LL res = 0; // 短作业工作时间需要累加（计入长作业等待时间）
  for (int i = 0; i < n; i ++ ) res += t[i] * (n - 1 - i);

  printf("%lld\n", res);
  return 0;
}