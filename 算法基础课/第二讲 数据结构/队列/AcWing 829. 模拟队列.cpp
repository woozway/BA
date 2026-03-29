#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N], hh, tt = -1; // hh<=tt表示队列内有元素
int m;

int main() {
  cin >> m;
  while (m -- ) {
    string op;
    int x;

    cin >> op;
    if (op == "push") cin >> x, q[ ++ tt] = x; // 这里和栈一样，++tt是为了保证tt指向队尾
    else if (op == "pop") hh ++ ;
    else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
    else cout << q[hh] << endl;
  }
  return 0;
}