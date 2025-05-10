#include <iostream>
using namespace std;
typedef long long ll;
const int N = 20;
int p[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> p[i];

  int res = 0;
  for (int i = 1; i < 1<<m; i++) {
    int t = 1, s = 0;
    for (int j = 0; j < m; j++)
      if (i>>j & 1) {
        if ((ll)t * p[j] > n) {
          t = -1;
          break;
        }
        t *= p[j];
        s++;
      }
    if (t != -1) {
      if (s % 2) res += n / t;
      else res -= n / t;
    }
  }
  cout << res << endl;
  return 0;
}