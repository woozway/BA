#include <bits/stdc++.h>
using namespace std;
const int N = 12, M = 1 << N;
int n, m;
long long f[N][M];
vector<int> state[M]; // state[i] 存储所有可以转移到状态 i 的合法状态
bool st[M]; // st[i] = true 表示状态 i 中所有连续 0 的段长度均为偶数（即可被竖骨牌填满）

// 核心：只需要枚举横放1x2骨牌，竖放是被“强制填充”的（总方案数 = 横着方块放置的方案数）
//                      / 集合：已将前i列摆好，且第i列状态是二进制j（从i-1列伸出到i列）的方案
//       / 状态表示f[i,j]
// DP问题                \ 属性：Count 数量
//       \ 
//         状态计算：按第i列有无i-1列横块伸出（j的二进制）来划分: k=0,1,2,..,2^n-1）
//          f[i,j] += f[i-1,k]（可优化，状态转移时只保留合法的k）
int main() {
  while (cin >> n >> m, n || m) {
    for (int i = 0; i < 1 << n; i ++ ) {
      int cnt = 0; // 预处理，剔除[0,2^n)中二进制内具有连续奇数个0的数字
      bool is_valid = true;
      for (int j = 0; j < n; j ++ )
        if (i >> j & 1) {
          if (cnt & 1) {
            is_valid = false;
            break;
          }
          cnt = 0;
        }
        else cnt ++ ;
      if (cnt & 1) is_valid = false;
      st[i] = is_valid;
    }

    for (int i = 0; i < 1 << n; i ++ ) { // i,j分别表示当前列，上一列是否有横块伸出的状态
      state[i].clear();
      for (int j = 0; j < 1 << n; j ++ )
        if ((i & j) == 0 && st[i | j]) // (i&j)=0 表示相邻状态i,j没有横块重叠；i|j 表示当前列所有已被横骨牌占用的位置，其余位置需用竖骨牌填，必须合法
          state[i].push_back(j); // 记录当前列状态的所有合法上一个列状态
    }

    memset(f, 0, sizeof f);
    f[0][0] = 1; // 前0列已摆好，且第0列没有前面的列摆放的横骨牌伸出j=0
    for (int i = 1; i <= m; i ++ ) // 遍历列从1开始，因为仅仅考虑横块时第0列伸出状态必是0
      for (int j = 0; j < 1 << n; j ++ ) // 遍历第i列是否有i-1横块伸出的所有状态
        for (auto k : state[j])
          f[i][j] += f[i - 1][k];

    cout << f[m][0] << endl; // 第0~m-1列全填满且m列无m-1列横块伸出的总方案数
  }

  return 0;
}