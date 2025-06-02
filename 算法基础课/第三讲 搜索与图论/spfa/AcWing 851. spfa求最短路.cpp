#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], w[N], ne[N], idx = 1;
int dist[N];
bool st[N]; // 用于记录是否已经在队列里

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa() { // 适合于稀疏图：优于bellman_ford，最差O(nm)，可处理负权边，可判断负环
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  st[1] = true;

  while (q.size()) { // spfa是对bf的优化，区别于bf的无脑更新，spfa使用队列只优化那些dist发生了变化的点
    auto t = q.front(); q.pop();
    st[t] = false;

    for (int i = h[t]; i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) { // 这里不能写成if (!st[j] && dist[j] > dist[t] + w[i])
        dist[j] = dist[t] + w[i];
        if (!st[j]) {
          q.push(j);
          st[j] = true;
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  while (m -- ) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }

  spfa();
  if (dist[n] == 0x3f3f3f3f) puts("impossible");
  else printf("%d\n", dist[n]);

  return 0;
}