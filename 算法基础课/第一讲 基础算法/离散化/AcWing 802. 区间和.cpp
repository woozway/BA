#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10; // n + m*2 可能有这么多离散的点
typedef pair<int, int> PII;
vector<PII> add, query;
vector<int> all; // all是排序去重后的所有离散的位置下标
int n, m, a[N], s[N]; // a是离散化后对应的连续数组

// vector<int>::iterator unique(vector<int> &a) {
//   int j = 0;
//   for (int i = 0; i < a.size(); i ++ )
//     if (!i || a[i] != a[i - 1])
//       a[j ++ ] = a[i];
//   return a.begin() + j; // a[0]~a[j-1]是所有a中不重复的数
// }

// 算出x离散化后的位置，分成两部分：(...), (x, ...)，前半<x，后半>=x
int find(int x) {
  int l = 0, r = all.size() - 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (all[mid] < x) l = mid + 1;
    else r = mid;
  }
  return l + 1; // 为方便后续前缀和查询操作（需从1开始映射）
}

// 将大值域（比如在[-10^9, 10^9]）中稀疏的点（比如10^5 个数）映射到从0/1开始连续数组中（可能有重复的数）
int main() {
  cin >> n >> m;

  int x, c;
  for (int i = 0; i < n; i ++ ) {
    scanf("%d%d", &x, &c);
    add.push_back({x, c});
    all.push_back(x);
  }

  int l, r;
  for (int i = 0; i < m; i ++ ) {
    scanf("%d%d", &l, &r);
    query.push_back({l, r});
    all.push_back(l), all.push_back(r);
  }

  sort(all.begin(), all.end()); // 排序
  all.erase(unique(all.begin(), all.end()), all.end()); // 去重
  // all.erase(unique(all), all.end()); // 自定义的unique

  for (auto it : add) { // 处理插入
    int x = find(it.first), c = it.second;
    a[x] += c;
  }

  for (int i = 1; i <= all.size(); i ++ ) s[i] = s[i - 1] + a[i]; // 预处理前缀和

  for (auto it : query) { // 处理询问
    int l = find(it.first), r = find(it.second);
    printf("%d\n", s[r] - s[l - 1]);
  }
  return 0;
}