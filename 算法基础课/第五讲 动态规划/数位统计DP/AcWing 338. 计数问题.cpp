#include <bits/stdc++.h>
using namespace std;

int get(vector<int> &num, int l, int r) { // 从数字数组中提取从第 l 位到第 r 位形成的数值
  int res = 0;
  for (int i = l; i >= r; i -- ) res = res * 10 + num[i];
  return res;
}

int power10(int x) { // 计算 10^x
  int res = 1;
  while (x -- ) res *= 10;
  return res;
}

// 假设要统计数字 x 在 n = abc(d)ef 的第 4 位出现的次数（即 num[i] = d）
// 我们将所有 1 ~ n 的数字分为两大类进行统计：
//   1. 000 ~ abc-1, x, 00 ~ 99（注：当 x = 0 时因为前导 0 需从 001 开始枚举）
//   2. abc, x, ..
//     2.1. d < x, 0
//     2.2. d = x, 0 ~ ef
//     2.3. d > x, 0 ~ 99
int count(int n, int x) { // 计算 1~n 中有几个数字 x
  if (!n) return 0;

  // num: [f e  d c b a]
  //       | .. | ..  |
  //       0 .. i .. m-1
  vector<int> num;
  while (n) {
    num.push_back(n % 10);
    n /= 10;
  }
  int res = 0, m = num.size();
  for (int i = m - 1 - !x; i >= 0; i -- ) { // 从高往低位遍历，最高位不能为0，否则有前导0
    if (i < m - 1) { // 如果当前数字不在最高位上
      res += get(num, m - 1, i + 1) * power10(i); // 计算：000 ~ abc-1, x, 00 ~ 99
      if (!x) res -= power10(i); // 如果x是0，前缀不能是全0，需扣除这种前缀的组合：000, 0, 00~99
    }
    if (num[i] == x) res += get(num, i - 1, 0) + 1; // abc, x, 0 ~ ef
    else if (num[i] > x) res += power10(i); // abc, x, 0 ~ 99
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