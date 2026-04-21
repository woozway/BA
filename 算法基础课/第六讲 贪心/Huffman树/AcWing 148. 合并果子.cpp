#include <bits/stdc++.h>
using namespace std;

// 因为较早合并的堆，其重量会被多次累加到后续的合并成本中。把小的重量放在“树”的深
// 层（多累加几次），把大的重量放在“树”的浅层（少累加几次），最终的总和才会最小
int main() {
  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> heap;
  while (n -- ) {
    int x;
    scanf("%d", &x);
    heap.push(x);
  }

  int res = 0;
  while (heap.size() > 1) {
    int a = heap.top(); heap.pop();
    int b = heap.top(); heap.pop();
    res += a + b;
    heap.push(a + b);
  }

  cout << res << endl;
  return 0;
}