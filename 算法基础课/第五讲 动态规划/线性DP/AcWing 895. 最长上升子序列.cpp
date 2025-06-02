#include <iostream>
using namespace std;
const int N = 1010;
int n;
int a[N], f[N];

//                      / 集合：所有以第i个数结尾的上升子序列
//        / 状态表示f[i]
// DP问题               \ 属性：Max
//        \
//          状态计算：集合的划分（枚举倒数第2个结尾位置j：0,1,...,i-1）
int main() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];

  for (int i = 1; i <= n; i ++ ) {
    f[i] = 1; // 只有a[i]一个数
    for (int j = 1; j < i; j ++ )
      if (a[j] < a[i])
        f[i] = max(f[i], f[j] + 1);
  }

  int res = 0;
  for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);
  cout << res << endl;

  return 0;
}