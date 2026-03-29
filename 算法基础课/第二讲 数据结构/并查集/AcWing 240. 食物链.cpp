#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int p[N], d[N]; // p[i]表示节点i的父节点，d[i]表示节点i到其当前父节点p[i]的距离
int n, k;

int find(int x) {
  if (p[x] != x) {
    int t = find(p[x]);
    d[x] += d[p[x]]; // 这里d[p[x]]已经更新了，另外d[x]要在p[x]更新前更新
    p[x] = t;
  }
  return p[x];
}

// 按照d[i]%3来判断谁吃谁；如果x,y在同一集合，且d[x]=d[y]+1，那么x吃y
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i ++ ) p[i] = i;

  int res = 0;
  while (k -- ) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (x > n || y > n) res ++ ;
    else {
      int px = find(x), py = find(y);
      if (t == 1) { // x和y同类，(d[x]-d[y])%3 == 0
        if (px == py) {
          if ((d[x] - d[y]) % 3) res ++ ;
        }
        else { // 合并并更新d：(d[x]+d[px]-d[y])%3 == 0
          p[px] = py;
          d[px] = d[y] - d[x]; // 前面是px，后面是y和x（d[x], d[y]会在调用find时被更新）
        }
      }
      else { // x吃y, (d[x]-1 - d[y])%3 == 0
        if (px == py) {
          if ((d[x] - 1 - d[y]) % 3) res ++ ;
        }
        else { // (d[x]+d[px]-1 - d[y])%3 == 0
          p[px] = py;
          d[px] = d[y] + 1 - d[x];
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}