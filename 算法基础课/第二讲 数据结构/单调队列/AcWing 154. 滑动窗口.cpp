#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], q[N]; // 单调队列q存的是下标

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int hh = 0, tt = -1;
  for (int i = 0; i < n; i++) {
    if (hh<=tt && q[hh]<i-k+1) hh++; // 将超出窗口范围的元素出队

    while (hh<=tt && a[q[tt]]>=a[i]) tt--; // 如果a[j]<a[i]且j>i，那么可以删去i
    q[++tt] = i;

    if (i >= k-1) printf("%d ", a[q[hh]]);
  }

  puts("");

  hh = 0, tt = -1;
  for (int i = 0; i < n; i++) { // 镜像问题
    if (hh<=tt && q[hh]<i-k+1) hh++;

    while (hh<=tt && a[q[tt]]<=a[i]) tt--;
    q[++tt] = i;

    if (i >= k-1) printf("%d ", a[q[hh]]);
  }

  return 0;
}