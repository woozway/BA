#include <iostream>
using namespace std;

int main() {
  double n;
  cin >> n;

  double l = -100, r = 100;
  double eps = 1e-8; // 8=6+2，保留6位，经验上多2位
  while (l < r-eps) {
    double mid = (l+r) / 2;
    if (mid*mid*mid < n) l = mid; // 浮点数二分就不用考虑+1那些了
    else r = mid;
  }
  printf("%.6lf\n", l); // 加.是控制小数精度，不加.控制位宽

  return 0;
}