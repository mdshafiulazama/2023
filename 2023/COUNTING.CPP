#include <iostream>
#include <vector>
#include <string>
#include <vector>
using namespace std;
void calculate_prefix_sum(const string& binary_string, vector<int>& prefix_sum) {
    int sum = 0;
    prefix_sum.push_back(0);
    for (char c : binary_string) {
        sum += (c == '1') ? 1 : 0;
        prefix_sum.push_back(sum);
    }
}
void scale_matrix(const vector<string>& binary_matrix, int K, string& binary_string) {
    int N = binary_matrix.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < K; l++) {
                    binary_string += binary_matrix[i][k];
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N, K;
        cin >> N >> K;

        vector<string> binary_matrix(N);
        for (int i = 0; i < N; i++) {
            cin >> binary_matrix[i];
        }

        string binary_string;
        int n2k2 = N * N * K * K;
        binary_string.reserve(n2k2);
        scale_matrix(binary_matrix, K, binary_string);

        vector<int> prefix_sum;
        calculate_prefix_sum(binary_string, prefix_sum);

        int Q;
        cin >> Q;
        cout << "Case " << caseNum << ":\n";

        for (int i = 0; i < Q; i++) {
            int L, R;
            cin >> L >> R;
            int result = prefix_sum[R + 1] - prefix_sum[L];
            cout << result << "\n";
        }
    }

    return 0;
}