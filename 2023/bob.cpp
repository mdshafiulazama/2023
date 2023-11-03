#include <iostream>
#include <cstdlib>
using namespace std;
long long calculate_answer(int A, long long N) {
    long long total = 0;
    for (long long i = 1; i <= N; i++) {
        total += abs(i % A - i % (A - 1));
    }
    return total;
}

int main() {
    int T;
    cin >> T;

    for (int case_number = 1; case_number <= T; case_number++) {
        int A;
        long long N;
        cin >> A >> N;
        long long answer = calculate_answer(A, N);
        cout << "Case " << case_number << ": " << answer << endl;
    }

    return 0;
}