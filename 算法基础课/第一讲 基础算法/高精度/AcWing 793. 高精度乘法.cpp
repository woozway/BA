#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, int b) { // 高精度大整数A>=0，整数b>=0
  vector<int> C;
  for (int i=0, t=0; i<A.size() || t; i++) { // 把整数一起乘，而不是一位位乘
    if (i < A.size()) t += A[i] * b;
    C.push_back(t % 10);
    t /= 10;
  }

  while (C.size()>1 && C.back()==0) C.pop_back();
  return C;
}

// // 附带两个都是大整数的实现方式，A>=0, B>=0
// vector<int> mul(vector<int> &A, vector<int> &B) {
//   vector<int> C(A.size()+B.size(), 0);
//   for (int i = 0; i < A.size(); i++)
//     for (int j = 0; j < B.size(); j++)
//       C[i+j] += A[i] * B[j];

//   for (int i = 0; i < C.size()-1; i++) {
//     C[i+1] += C[i] / 10;
//     C[i] %= 10;
//   }

//   while (C.size()>1 && C.back()==0) C.pop_back();
//   return C;
// }

int main() {
  string a;
  int b;
  cin >> a >> b;

  vector<int> A;
  for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');

  auto C = mul(A, b);

  for (int i = C.size()-1; i >= 0; i--) printf("%d", C[i]);
  cout << endl;

  return 0;
}