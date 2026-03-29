#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], ph[N], hp[N], cnt; // ph[k]：第k个插入数在h中的下标，hp[k]：h中下标k的数对应之前第几个插入

/*        /\                  /\
 *  ph[a]/  \           ph[b]/  \
 *     \/    \ ph[b]       \/    \ ph[a]
 *     /hp[a] \/   ====>   /hp[b] \/
 *    /   hp[b]\          /   hp[a]\
 */
void heap_swap(int a, int b) { // 交换堆中a和b两个位置的数及其hp,ph索引（这里参数a,b是下标）
  swap(ph[hp[a]], ph[hp[b]]);
  swap(hp[a], hp[b]);
  swap(h[a], h[b]);
}

void down(int u) {
  int t = u;
  if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
  if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
  if (t != u) {
    heap_swap(u, t);
    down(t);
  }
}

void up(int u) {
  while (u / 2 && h[u / 2] > h[u]) {
    heap_swap(u / 2, u);
    u >>= 1;
  }
}

int main() {
  int n, idx = 0;

  cin >> n;
  while (n -- ) {
    string op;
    int k, x;

    cin >> op;
    if (op == "I") {
      cin >> x;
      idx ++ ; // 记录当前是第几个插入的数（不能复用cnt）
      cnt ++ ; // 因为cnt是动态变的，而idx一旦确定后是不变的
      ph[idx] = cnt, hp[cnt] = idx;
      h[cnt] = x, up(cnt); // 连续动作
    }
    else if (op == "PM") cout << h[1] << endl;
    else if (op == "DM") heap_swap(1, cnt -- ), down(1);
    else if (op == "D") {
      cin >> k;
      k = ph[k];
      heap_swap(k, cnt -- ), up(k), down(k); // up和down最多执行一个
    }
    else {
      cin >> k >> x;
      k = ph[k];
      h[k] = x, up(k), down(k);
    }
  }
  return 0;
}