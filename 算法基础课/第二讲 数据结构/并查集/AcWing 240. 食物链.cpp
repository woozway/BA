#include <iostream>
using namespace std;
const int N = 5e4 + 10;
int p[N], d[N]; // d[i]维护i节点到根的距离

int find(int x) {
  if (p[x] != x) {
    int t = find(p[x]);
    d[x] += d[p[x]]; // find之后p[x]已经发生变化
    p[x] = t;
  }
  return p[x];
}

int main() { // 按照d[i]%3来判断谁吃谁；如果x,y在同一集合，且dx=dy+1，那么x吃y
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i ++ ) p[i] = i;

  int res = 0;
  while (k -- ) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (x > n || y > n) res ++ ;
    else {
      int px = find(x), py = find(y);
      if (t == 1) { // x和y同类，(dx-dy)%3 == 0
        if (px == py) {
          if ((d[x] - d[y]) % 3) res ++ ;
        }
        else { // 合并并更新d：(d[x]+d[px]-dy)%3 == 0
          p[px] = py;
          d[px] = d[y] - d[x]; // 前面是px，后面是y和x（dx/dy在调用find时再更新）
        }
      }
      else { // x吃y, (dx-dy-1)%3 == 0
        if (px == py) {
          if ((d[x] - 1 - d[y]) % 3) res ++ ;
        }
        else { // (d[x)+d[px]-d[y]-1)%3 == 0
          p[px] = py;
          d[px] = d[y] + 1 - d[x];
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}