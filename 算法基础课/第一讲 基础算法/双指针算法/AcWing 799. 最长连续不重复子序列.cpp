#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], s[N]; // s[i]用于标记维护的窗口中a[i]出现了多少次，也可用哈希表

// // 双指针用于优化O(n^2)到O(n)，模版如下：
// for (int i = 0, j = 0或n-1; i < n; i ++ ) {
//   while ((j < i 或 j >= 0) && check(i, j)) j++ 或 j--;
//   // 每道题的具体逻辑，检查当check(i,j)满足时...
// }

// 维护一个所有不同元素都只出现过一次的最大窗口: [j,i]
int main() {
  cin >> n;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  // 反证法：可证明j是单调变大的，假如当前窗口是[j,i]，那么当i更新成i+1时，
  // 如果有新的j'小于原来的j，那么之前的窗口区间本可以更新成[j',i]，矛盾
  int res = 0; // 双指针模版for + while：1. 暴力做法；2. 检查i,j关系是否能优化
  for (int i = 0, j = 0; i < n; i ++ ) { // [j~i]是窗口范围，j表示窗口左侧所能达到的最远端点
    s[a[i]] ++ ; // i往右扩展区间，窗口中加入新元素a[i]，可能破坏区间里元素都只出现1次这个条件
    while (j <= i && s[a[i]] > 1) s[a[j ++ ]] -- ; // j只往右走；处理完后窗口内又恢复各元素都只出现1次
    if (j <= i) res = max(res, i - j + 1); // while处理完后可以检查，更新
  }

  cout << res << endl;
  return 0;
}