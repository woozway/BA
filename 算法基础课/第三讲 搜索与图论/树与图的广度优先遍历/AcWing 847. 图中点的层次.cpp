#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx = 1;
int d[N]; // d[i]表示从1到i的最短距离，初始化为不可达-1
int n, m;

void add(int a , int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs() {
  memset(d, -1, sizeof d); // 因为起始点d[1]=0，所以0不能作为未初始化标识
  queue<int> q;

  d[1] = 0;
  q.push(1);

  while (q.size()) {
    auto t = q.front(); q.pop();
    for (int i = h[t]; i; i = ne[i]) {
      int j = e[i];
      if (d[j] == -1) {
        d[j] = d[t] + 1;
        q.push(j);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  while (m -- ) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }

  bfs();
  cout << d[n] << endl;
  return 0;
}