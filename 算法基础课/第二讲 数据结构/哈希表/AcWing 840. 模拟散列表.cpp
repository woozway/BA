// 开放寻址法
#include <bits/stdc++.h>
using namespace std;
const int N = 200003, null = 0x3f3f3f3f; // N是一个素数
int n, h[N]; // 这里取N=n*2是因为查找次数S=1/2*(1 + 1/(1-a))，其中a为装填因子

int find(int x) { // 为x找一个null的位置t
  int t = (x % N + N) % N; // 将可能是负数的x转为N范围内的正数，0<=t<N
  while (h[t] != null && h[t] != x) {
    t ++ ;
    if (t == N) t = 0;
  }
  return t;
}

int main() {
  memset(h, 0x3f, sizeof h);

  cin >> n;
  while (n -- ) {
    string op;
    int x;

    cin >> op >> x;
    if (op == "I") h[find(x)] = x;
    else {
      if (h[find(x)] == null) cout << "No" << endl;
      else cout << "Yes" << endl;
    }
  }
  return 0;
}

// // 拉链法
// #include <iostream>
// using namespace std;
// const int N = 100003; // 素数
// int h[N], e[N], ne[N], idx = 1;
// int n;

// void insert(int x) { // 头插法
//   int k = (x % N + N) % N;
//   e[idx] = x, ne[idx] = h[k], h[k] = idx ++ ;
// }

// bool query(int x) {
//   int k = (x % N + N) % N;
//   for (int i = h[k]; i; i = ne[i])
//     if (e[i] == x) return true;
//   return false;
// }

// int main() {
//   cin >> n;
//   while (n -- ) {
//     char op;
//     int x;

//     cin >> op >> x;
//     if (op == 'I') insert(x);
//     else puts(query(x) ? "Yes" : "No");
//   }
//   return 0;
// }