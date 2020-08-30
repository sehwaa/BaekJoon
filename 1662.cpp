#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  string s;
  cin >> s;

  stack<char> stack;

  for (int i = 0; i < s.length(); i++) {
    stack.push(s[i]);
  }

  int K = 0;
  string Q = "";

  while(!stack.empty()) {
    if (stack.top() != '(' && stack.top() != ')') {
      Q += stack.top();
      stack.pop();
      cout << "Q: " << Q << endl;
    } else if (stack.top() == '(') {
      stack.pop();
      K = stack.top() - '0';
      string temp = Q;
      cout << "temp: "<< temp << endl;
      for (int i = 1; i < K; i++) {
        Q += temp;
      }
      stack.pop();
      cout << "K: "<< K << endl;
      cout << "Q2:" << Q << endl;
    } else {
      stack.pop();
    }
  }

  cout << Q.length() <<endl;

  return 0;
}