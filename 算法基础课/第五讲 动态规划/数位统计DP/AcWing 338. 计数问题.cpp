#include <iostream>
#include <vector>
using namespace std;

// n = abc(d)efg, num[i] = d, x是要查询的数字
// 1. 000~abc-1, x, 000~999（x=0时因为前导0需从001开始枚举）
// 2. abc, x
//     2.1. d < x, 0
//     2.2. d = x, 0~efg
//     2.3. d > x, 0~999
int get(vector<int> &num, int l, int r) {
  int res = 0;
  for (int i = l; i >= r; i -- ) res = res * 10 + num[i];
  return res;
}

int power10(int x) {
  int res = 1;
  while (x -- ) res *= 10;
  return res;
}

int count(int n, int x) {
  if (!n) return 0;

  vector<int> num;
  while (n) {
    num.push_back(n % 10);
    n /= 10;
  }
  n = num.size();

  int res = 0;
  for (int i = n - 1 - !x; i >= 0; i -- ) { // 从高位往低位遍历，当n-1位为0时，所有右边数字的组合都有前导0不合法，可直接跳过
    if (i < n - 1) { // 如果当前数字不在最高位上
      res += get(num, n - 1, i + 1) * power10(i);
      if (!x) res -= power10(i);
    }

    if (num[i] == x) res += get(num, i - 1, 0) + 1;
    else if (num[i] > x) res += power10(i);
  }
  return res;
}

int main() {
  int a, b;
  while (cin >> a >> b, a) {
    if (a > b) swap(a, b);

    for (int i = 0; i <= 9; i ++ )
        cout << count(b, i) - count(a - 1, i) << ' ';
    cout << endl;
  }
  return 0;
}