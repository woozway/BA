#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 12, M = 1 << N;
int n, m;
long long f[N][M];
vector<int> state[M];
bool st[M];

// 核心：先放横着的方块，再放竖着的（因为总方案数=横着方块放置的方案数）

//                       / 集合：已经将前i-1列摆好，且从i-1列伸出到i列的所有方案
//       / 状态表示f[i,j]
// DP问题                \ 属性：数量
//       \ 
//         状态计算：集合的划分（以第i列伸/不伸出来划分0,1,2,..,2^n-1中状态）
//          f[i,j] += f[i-1,k]（可优化，只保留合法的）
int main() {
  while (cin >> n >> m, n || m) {
    for (int i = 0; i < 1<<n; i++) {
      int cnt = 0; // 预处理，将二进制中存在连续奇数个0的数标记为不合法
      bool is_valid = true;
      for (int j = 0; j < n; j++)
        if (i>>j & 1) {
          if (cnt & 1) {
            is_valid = false;
            break;
          }
          cnt = 0;
        }
        else cnt++;
      if (cnt & 1) is_valid = false;
      st[i] = is_valid;
    }

    for (int i = 0; i < 1<<n; i++) { // i,j分别表示当前列，上一列的所有状态
      state[i].clear();
      for (int j = 0; j < 1<<n; j++)
        if ((i & j)==0 && st[i | j]) // st[i|j]=1表示当前列，上一列都不存在连续奇数个0
          state[i].push_back(j); // 记录当前列状态的所有合法上一个列状态
    }

    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 0; j < 1<<n; j++) // 遍历第i列的所有状态
        for (auto k: state[j])
          f[i][j] += f[i-1][k];

    cout << f[m][0] << endl; // 第m列状态为0（第0~m-1列全填满且没有伸出）的方案数
  }

  return 0;
}