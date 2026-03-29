#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII; // 需要(距离，下标)来存，这样每次取到距离最近O(1)
const int N = 1.5e5 + 10, M = N;
int h[N], e[M], w[M], ne[M], idx = 1; // 稀疏图用邻接表；w[]存边权
int dist[N];
bool st[N]; // 存储每个点的最短路是否已确定
int n, m;

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra() { // O(mlgn) 稀疏图用邻接表 + 堆优化版 dijkstra
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q; // 小根堆
  q.push({dist[1], 1});

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
  cin >> n >> m;
  while (m -- ) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c); // 邻接表可以不处理图的重边&自环：因为w>0，自环时if (dist[j] > dist[ver] + w[i])恒为假；重边时算法会自动选择最小的
  }

  dijkstra();

  if (dist[n] == 0x3f3f3f3f) cout << -1 << endl;
  else cout << dist[n] << endl;
  return 0;
}