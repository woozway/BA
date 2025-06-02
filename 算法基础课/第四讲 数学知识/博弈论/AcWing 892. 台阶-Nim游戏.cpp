#include <iostream>
using namespace std;
const int N = 1e5 + 10;

// 偶数级台阶上没有影响，奇数级台阶上全部异或!=0先手必胜，否则先手必败

// 对于奇数级台阶（经典Nim游戏）：
// 若a1 ^ a3 ^ ... ^ a2k+1 = x (x != 0)，则必可以从某一堆中拿走石子，以使a1 ^ .. ^ an = 0
// 对于偶数级台阶：从2k往2k-1拿多少，那就从2k-1往2k-2拿多少
int main() {
  int n;
  scanf("%d", &n);

  int res = 0;
  for (int i = 1; i <= n; i ++ ) {
    int x;
    scanf("%d", &x);
    if (i & 1) res ^= x;
  }

  if (res) puts("Yes");
  else puts("No");
  return 0;
}