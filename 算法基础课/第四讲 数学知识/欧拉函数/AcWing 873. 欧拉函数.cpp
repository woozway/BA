#include <iostream>
using namespace std;

// 欧拉函数：phi(x) 表示在 1~x 中，与 x 互质（即最大公约数为 1）的整数个数
// 核心结论：phi(x) 的大小只跟 x 的质因数种类有关，跟质因数出现了多少次无关
int phi(int x) { // φ(x) = x * (1-1/p1) * ... * (1-1/pk)
  int res = x;
  for (int i = 2; i <= x / i; i ++ )
    if (x % i == 0) {
      res = res / i * (i - 1); // (1-1/p)
      while (x % i == 0) x /= i;
    }
  if (x > 1) res = res / x * (x - 1);

  return res;
}

int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int a;
    cin >> a;
    cout << phi(a) << endl;
  }
  return 0;
}