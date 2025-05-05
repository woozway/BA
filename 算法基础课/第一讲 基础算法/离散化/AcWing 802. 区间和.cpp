#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e5 + 10; // n + m*2
typedef pair<int, int> pii;
vector<pii> add, query;
vector<int> all; // all是所有离散的位置下标
int a[N], s[N];

int find(int x) {
  int l = 0, r = all.size()-1;
  while (l < r) {
    int mid = l+r >> 1;
    if (all[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return l + 1; // 方便后续前缀和下标操作（从1开始索引）
}

int main() {
  int n, m;
  cin >> n >> m;

  int x, c;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &c);
    add.push_back({x, c});
    all.push_back(x);
  }

  int l, r;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    query.push_back({l, r});
    all.push_back(l), all.push_back(r);
  }

  sort(all.begin(), all.end()); // 排序，去重
  all.erase(unique(all.begin(), all.end()), all.end());

  for (auto it: add) { // 处理插入
    int x = find(it.first), c = it.second;
    a[x] += c;
  }

  for (int i = 1; i <= all.size(); i++) s[i] = s[i-1] + a[i]; // 预处理前缀和

  for (auto it: query) { // 处理询问
    int l = find(it.first), r = find(it.second);
    printf("%d\n", s[r] - s[l-1]);
  }

  return 0;
}