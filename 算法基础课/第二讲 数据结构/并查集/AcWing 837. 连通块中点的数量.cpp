#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N], cnt[N]; // cnt[i]表示i所归属的集合size

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    cnt[i] = 1;
  }

  string op;
  int a, b;
  while (m--) {
    cin >> op;
    if (op == "C") {
      cin >> a >> b;
      a = find(a), b = find(b);
      if (a != b) {
        p[a] = b;
        cnt[b] += cnt[a];
      }
    }
    else if (op == "Q1") {
      cin >> a >> b;
      cout << (find(a)==find(b) ? "Yes" : "No") << endl;
    }
    else {
      cin >> a;
      cout << cnt[find(a)] << endl;
    }
  }

  return 0;
}