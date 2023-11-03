#include <bits/stdc++.h>
using namespace std;

int Q(int J, int K) {
    if (J < K) {
        return 5;
    } else {
        return Q(J - K, K + 2) + J;
    }
}

int main() {
    int J, K;

    cout << "Enter the value for J: ";
    cin >> J;
    cout << "Enter the value for K: ";
    cin >> K;

    int result = Q(J, K);

    cout << "Q(" << J << ", " << K << ") = " << result << endl;

    return 0;
}
