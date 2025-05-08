#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100010, mod = 1e9 + 7;

int qmi(int a, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) res = (ll)res * a % p;
    a = (ll)a * a % p;
    k >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  int a = n*2, b = n;
  int res = 1;
  for (int i = a; i > a-b; i--) res = (ll)res * i % mod;

  for (int i = 1; i <= b; i++) res = (ll)res * qmi(i, mod-2, mod) % mod;

  res = (ll)res * qmi(n+1, mod-2, mod) % mod;
  cout << res << endl;

  return 0;
}