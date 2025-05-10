#include <iostream>
using namespace std;
const int N = 100010;

int main() {
  int n;
  scanf("%d", &n);

  int res = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (i & 1) res ^= x;
  }

  if (res) puts("Yes");
  else puts("No");
  return 0;
}