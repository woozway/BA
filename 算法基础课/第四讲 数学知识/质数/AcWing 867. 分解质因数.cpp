#include <iostream>
using namespace std;

void divide(int x) { // 枚举到i时，x中已经没有2~i-1中所有的质因子
  for (int i = 2; i <= x/i; i++)
    if (x % i == 0) { // 这里i一定是质数：每次剥离因数后，不会再检查这个因数的倍数
      int s = 0;
      while (x % i == 0) x /= i, s++;
      cout << i << ' ' << s << endl;
    }
  if (x > 1) cout << x << ' ' << 1 << endl;
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    divide(a);
  }
  return 0;
}