#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 0; i < m; i++) scanf("%d", &b[i]);

  int cnt = 0;
  for (int i=0, j=0; i < n; i++) {
    while (j<m && b[j]!=a[i]) j++;
    if (j < m) cnt++, j++; // 说明b[j]==a[i]，匹配个数+1
  }

  if (cnt == n) puts("Yes");
  else puts("No");

  return 0;
}