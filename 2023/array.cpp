#include <iostream>
#include <vector>
using namespace std;
int countNonBeautifulSubarrays(vector<int> arr) {
    int result = 0;
    int i = 0;
    while (i < arr.size()) {
        int count = 1;
        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
            count += 1;
            i += 1;
        }
        result += (count * (count + 1)) / 2;
        i += 1;
    }
    return result;
}
int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int nonBeautifulCount = countNonBeautifulSubarrays(A);
        cout << "case " << t << ": " << N * (N + 1) / 2 - nonBeautifulCount << endl;
    }
    return 0;
}