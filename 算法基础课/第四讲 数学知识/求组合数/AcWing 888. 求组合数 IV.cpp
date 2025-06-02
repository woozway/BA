#include <iostream>
#include <vector>
using namespace std;
const int N = 5010;
int sum[N], primes[N], cnt;
bool st[N];

void get_primes(int n) {
  for (int i = 2; i <= n; i ++ ) {
    if (!st[i]) primes[cnt ++ ] = i;
    for (int j = 0; primes[j] <= n / i; j ++ ) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

int get(int n, int p) { // 获取n!中出现p的次数
  int res = 0;
  while (n) {
    res += n / p;
    n /= p;
  }
  return res;
}

vector<int> mul(vector<int> &a, int b) {
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || t; i ++ ) {
    if (i < a.size()) t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }
  while (c.size() > 1 && c.back() == 0) c.pop_back();
  return c;
}

// c(a,b) = a!/[b! * (a-b)!], 在分子&分母上分解质因子，然后高精度乘
int main() {
  int a, b;
  cin >> a >> b;

  get_primes(a);
  for (int i = 0; i < cnt; i ++ ) {
    int p = primes[i];
    sum[i] = get(a, p) - get(a - b, p) - get(b, p);
  }

  vector<int> res;
  res.push_back(1);
  for (int i = 0; i < cnt; i ++ )
    for (int j = 0; j < sum[i]; j ++ )
      res = mul(res, primes[i]);

  for (int i = res.size() - 1; i >= 0; i -- ) printf("%d", res[i]);
  puts("");
  return 0;
}