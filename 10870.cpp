#include <iostream>

using namespace std;

int fibonacci(int N) {
  if (N == 0) return 0;
  else if (N == 1) return 1;
  else return fibonacci(N-2) + fibonacci(N-1);
}

int main() {
  int N;
  cin >> N;
  int answer = 0;
  for (int i = 0; i <= N; i++) {
    answer = fibonacci(i);
  }
  cout << answer;
  return 0;
}