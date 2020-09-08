#include <iostream>
#include <queue>

using namespace std;

vector < int > v;
int count = 0;
void swap(int *a, int *b) {
	int temp = *a; *a = *b; *b = temp;
}
void push(int x, int index) {
	int child = index;
	int parent = child / 2;
	while (parent > 1) {
		if (v[parent] < v[child]) {
			swap(&v[parent], &v[child]);
			child = parent;
			parent = child / 2;
		}
	}
}
int pop() {
	int result = v[0];
	v.erase(v.begin());
	return result;
}
int main() {
	int N;
	cin >> N;
	
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x != 0) {
			count++;
      v.push_back(x);
			push(x, i);
		} else {
			if (count == 0) {
				cout << 0 << endl;
			} else {
				int result = pop();
				cout << result << endl;
				count--;
			}
		}
	}
	return 0;
}