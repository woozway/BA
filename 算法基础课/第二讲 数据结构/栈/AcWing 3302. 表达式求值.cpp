#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
stack<int> num;
stack<char> op;

void eval() {
  auto b = num.top(); num.pop();
  auto a = num.top(); num.pop();
  auto c = op.top(); op.pop();
  int x;
  if (c == '+') x = a + b;
  else if (c == '-') x = a - b;
  else if (c == '*') x = a * b;
  else x = a / b;
  num.push(x);
}

int main() {
  unordered_map<char, int> pr{{'+',1}, {'-',1}, {'*',2}, {'/',2}};

  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    auto c = str[i];
    if (isdigit(c)) {
      int x = 0, j = i;
      while (j<str.size() && isdigit(str[j])) x = x*10 + str[j++]-'0';
      num.push(x);
      i = j - 1;
    }
    else if (c == '(') op.push(c);
    else if (c == ')') {
      while (op.top() != '(') eval();
      op.pop();
    }
    else { // 中缀表达式判断左右子树已经遍历完：当栈顶的运算符优先级>=当前运算符
      while (op.size() && pr[op.top()]>=pr[c]) eval(); // 其他语言需要加 && op.top()!='('，因为'('的优先级之前没定义
      op.push(c);
    }
  }

  while (op.size()) eval();
  cout << num.top() << endl;

  return 0;
}