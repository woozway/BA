#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int stk[N], tt;

// 注意到如序列[3 4 2 7 5]，因3>=2且2在3右边，因此只要2在，3永远不会轮到，可直接删去
int main() { // 单调栈一般用于找左/右边最近的第一个比自己小/大的数
  int n;
  cin >> n;

  for (int i = 0; i < n; i ++ ) {
    int x;
    scanf("%d", &x);
    while (tt && stk[tt] >= x) tt -- ; // 当栈非空时，将栈中>=当前元素的出栈
    if (tt) printf("%d ", stk[tt]);
    else printf("-1 ");
    stk[ ++ tt] = x;
  }
  return 0;
}