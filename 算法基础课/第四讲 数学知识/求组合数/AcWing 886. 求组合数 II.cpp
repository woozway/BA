#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100010, mod = 1e9 + 7;
int n, fact[N], infact[N];

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
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (ll)fact[i-1] * i % mod;
    infact[i] = (ll)infact[i-1] * qmi(i, mod-2, mod) % mod;
  }

  cin >> n;
  while (n--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", (ll)fact[a] * infact[b] % mod * infact[a-b] % mod);
  }
  return 0;
}