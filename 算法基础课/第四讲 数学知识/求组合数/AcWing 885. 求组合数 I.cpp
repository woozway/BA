#include <iostream>
using namespace std;
const int N = 2010, mod = 1e9 + 7;
int c[N][N];

void init() { // O(N^2)
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      if (!j) c[i][j] = 1;
      else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
}

// 预处理(2*10^3)^2对c(a,b)：从a个苹果中选b个苹果，取出一个苹果，然后将
// 总方案数分为包含/不包含这个苹果的方案数：c(a,b) = c(a-1,b-1) + c(a-1,b)
int main() {
  init();

  int n;
  scanf("%d", &n);
  while (n--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", c[a][b]);
  }
  return 0;
}