#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	priority_queue< int, vector<int>, greater<int> > pq;
	
	int x;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x != 0) {
			pq.push(x);
		} else {
			if (pq.size() > 0) {
				printf("%d\n", pq.top());
				pq.pop();
			} else {
				printf("%d\n", 0);
			}
		}
	}

	return 0;
}