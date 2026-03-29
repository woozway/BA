#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> d; // d在这里也充当检查是否访问过的作用
string state;
int res = -1;

void bfs() {
  queue<string> q;
  d[state] = 0;
  q.push(state);

  int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
  string end = "12345678x";
  while (q.size()) {
    auto t = q.front(); q.pop();
    if (t == end) {
      res = d[t];
      return;
    }
    int distance = d[t]; // 这里要先备份，后面字符串t会变
    int p = t.find('x');
    int r = p / 3, c = p % 3; // p/3得x所在行，p%3得x所在列
    for (int i = 0; i < 4; i ++ ) {
      int x = r + dx[i], y = c + dy[i];
      if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        swap(t[x * 3 + y], t[p]);
        if (!d.count(t)) { // 这里不能用!d[t]，有副作用
          d[t] = distance + 1;
          q.push(t);
        }
        swap(t[x * 3 + y], t[p]); // 恢复现场
      }
    }
  }
}

int main() {
  for (int i = 0; i < 9; i ++ ) {
    string s;
    cin >> s;
    state += s;
  }

  bfs();
  cout << res << endl;
  return 0;
}