#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 10010;
int n, k, s[N], f[M]; // s[]存储k个允许拿走的石子数量，f[]用于记忆化搜索

// SG函数（Sprague-Grundy Function）的作用是为每个游戏状态（比如有 x 个石子）赋予一个数值
// SG(x) = 0：表示当前状态是必败态；SG(x) ≠ 0：表示当前状态是必胜态
// SG值的计算依赖于 mex 运算（minimal excludant，最小排斥值）
// mex(S) 的定义是：找出不在集合 S 中的最小非负整数：例mex{0,1,2,4} = 3，mex{} = 0
// 证明用 Nim 游戏方式（n 个 sg(x) 异或起来）：!=0：必胜；=0：必败
int sg(int x) { // SG(x) = mex({SG(y1), SG(y2), ..., SG(yk)})
  if (f[x] != -1) return f[x]; // 记忆化搜索

  unordered_set<int> S; // 用来存x所有后继状态的SG值
  for (int i = 0; i < k; i ++ )
    if (x >= s[i]) S.insert(sg(x - s[i]));

  for (int i = 0; ; i ++ ) // mex操作
    if (!S.count(i)) return f[x] = i;
}

// 以7为例，可取数字为2,5，()中是sg值
//        / 3(1) - 1(0), 这里mex{}=0
//    5(2)，这里5可以到达3和0，它们各自的sg值为1和0，因此mex{0,1}=2
//   /    \ 0(0)
// 7(0)
//   \ 
//    2(1) - 0(0)
int main() {
  cin >> k;
  for (int i = 0; i < k; i ++ ) cin >> s[i];
  cin >> n;

  memset(f, -1, sizeof f);

  int res = 0;
  while (n -- ) {
    int x;
    cin >> x;
    res ^= sg(x);
  }

  if (res) puts("Yes");
  else puts("No");
  return 0;
}