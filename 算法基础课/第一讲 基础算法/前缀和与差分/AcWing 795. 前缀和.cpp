#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int s[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i ++ ) { // 为不处理边界，s从1开始
    scanf("%d", &s[i]);
    s[i] += s[i - 1]; // 也可以先开一个数组a，s[i] = s[i-1] + a[i]
  }

  int l, r;
  while (m -- ) {
    scanf("%d%d", &l, &r);
    printf("%d\n", s[r] - s[l - 1]); // sum[l~r]
  }
  return 0;
}