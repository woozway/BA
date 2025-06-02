#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n;
int t[N];

// 总时间 = t1*(n-1) + t2*(n-2) + ... + tn-1*1 + tn*0
// 直觉：短作业优先SJF，将n个数从小打到排序，然后贪心
// 证明（调整法）：假设最优答案不是非递减序列，则必存在逆序对：ti > ti+1
// 交换的两项对其他项无影响，此时总时间为
//   前：ti*(n-i) + ti+1*(n-i-1)，后：ti+1*(n-i) + ti*(n-i-1)，
//   前-后：ti - ti+1 > 0，说明可以更优，与假设矛盾，得证
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++ ) scanf("%d", &t[i]);

  sort(t, t + n);
  reverse(t, t + n);

  LL res = 0;
  for (int i = 0; i < n; i ++ ) res += t[i] * i;

  printf("%lld\n", res);
  return 0;
}