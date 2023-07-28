#include <iostream>
#include <queue>
using namespace std;
int heap[100001];
priority_queue<int, vector<int>, greater<int> > minHeap;
int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            if (minHeap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            }
        } else {
            minHeap.push(op);
        }
    }
    return 0;
}

// endl은 출력 버퍼를 비워주는 역할도 하기 때문에 endl 보다 '\n'을 사용하는 것이 더 빠름