#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: " << endl;


    priority_queue<int> maxHeap;


    priority_queue<int, vector<int>, greater<int>> minHeap;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        maxHeap.push(num);
        minHeap.push(num);
    }


    cout << "Max Heap is: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;


    cout << "Min Heap is: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
