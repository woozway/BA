#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N], hh, tt = -1; // 单调队列q存的是下标，方便移除已不在窗口内的数
int a[N];
int n, k;

// 注意到如序列[1 3 -1 -3 5 3 6 7]，因为3>=-1且-1在3右边，只要-1在，3一定不是最小值的候选，可直接删去
int main() { // 单调队列可解决给定窗口内的最大/小值问题
  cin >> n >> k;
  for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  for (int i = 0; i < n; i ++ ) {
    if (hh <= tt && q[hh] < i - k + 1) hh ++ ; // 将超出窗口范围的元素出队

    while (hh <= tt && a[q[tt]] >= a[i]) tt -- ; // 如果a[j]<a[i]且j>i，那么可以删去i
    q[ ++ tt] = i;

    if (i >= k - 1) printf("%d ", a[q[hh]]); // 把>=当前元素的都撸掉了，处理后窗口中的元素当然是严格升序的
  }

  puts("");

  hh = 0, tt = -1;
  for (int i = 0; i < n; i ++ ) { // 镜像问题
    if (hh <= tt && q[hh] < i - k + 1) hh ++ ;

    while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
    q[ ++ tt] = i;

    if (i >= k - 1) printf("%d ", a[q[hh]]);
  }

  return 0;
}