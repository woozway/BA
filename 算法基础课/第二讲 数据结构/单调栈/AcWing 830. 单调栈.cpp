#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int stk[N], tt;

int main() { // 单调栈一般用于找左/右边最近的第一个比自己小/大的数
  int n;
  cin >> n;

  int x;  
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    while (tt && stk[tt]>=x) --tt; // 当栈非空时，将栈中>=当前元素的出栈
    if (tt) printf("%d ", stk[tt]);
    else printf("-1 ");
    stk[++tt] = x;
  }

  return 0;
}