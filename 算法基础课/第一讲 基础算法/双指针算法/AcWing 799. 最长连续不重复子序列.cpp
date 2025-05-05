#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N]; // s[i]用于标记维护的窗口中i出现了多少次，也可以用哈希表

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int res = 0; // 双指针模版for+while：1. 朴素做法；2. 检查i,j关系是否能优化
  for (int i=0, j=0; i < n; i++) { // [i~j]是窗口范围，j表示窗口左侧所能达到的最远端点
    s[a[i]]++; // i往右扩展区间，窗口中加入新元素a[i]，可能破坏区间里元素都只出现1次这个条件
    while (j<=i && s[a[i]]>1) s[a[j++]]--; // j只会往右走；处理完后窗口内又恢复各元素都只出现1次
    res = max(res, i-j+1);
  }

  cout << res << endl;

  return 0;
}