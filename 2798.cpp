#include <iostream>

using namespace std;

#define MAX_CARD 3
#define MAX_NUMBER 100000

int N, M;
int card[MAX_NUMBER];
int sum = 0;
int maxSum = 0;

void pick (int index, int count) {
	sum += card[index];
	
	if (count == MAX_CARD) {
		if (sum > maxSum && sum <= M)	maxSum = sum;
		return;
	}
	
	for (int i = index+1; i < N; i++) {
		pick(i, count + 1);
		sum -= card[i];
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	
	for (int i = 0; i < N; i++) {
		pick(i, 1);
		sum = 0;
	}
	
	cout << maxSum;
	return 0;
}