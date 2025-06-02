#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

//                     / 集合：所有由第1个序列的前i个字符，和第2个序列的前j个字符构成的LCS
//      / 状态表示f[i,j]
// DP问题               \ 属性：Max
//      \
//        状态计算：集合的划分按a[i],b[j]是否在答案中（00,01,10,11）
// 其中00: f[i-1,j-1], 11: f[i-1,j-1] + 1, 01: f[i-1,j], 10: f[i,j-1]（并不完全等价但包含10，01同理）
int main() {
  cin >> n >> m;
  cin >> a + 1 >> b + 1;

  for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ ) {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
    }
  cout << f[n][m] << endl;

  return 0;
}