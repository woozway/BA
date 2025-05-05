#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii; // 需要(距离，下标)来存，这样每次取到距离最近O(1)
const int N = 1.5e5 + 10;
int h[N], e[N], w[N], ne[N], idx = 1; // 稀疏图用邻接表；w[]存边权
int dist[N];
bool st[N];

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() { // 稀疏图用邻接表 + 堆优化dijkstra
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q; // 小根堆
  q.push({0, 1});

  while (q.size()) {
    auto t = q.top(); q.pop();

    int ver = t.second;
    if (st[ver]) continue; // STL的堆没有删除操作，这里取出的ver可能已经标记过（懒删除）
    st[ver] = true;

    for (int i = h[ver]; i; i = ne[i]) { // 用新加入的ver更新到其他点的最小距离
      int j = e[i];
      if (dist[j] > dist[ver] + w[i]) {
        dist[j] = dist[ver] + w[i];
        q.push({dist[j], j});
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  while (m--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z); // 邻接表可以不用处理图的重边和自环
  }

  dijkstra();

  if (dist[n] == 0x3f3f3f3f) cout << -1 << endl;
  else cout << dist[n] << endl;

  return 0;
}