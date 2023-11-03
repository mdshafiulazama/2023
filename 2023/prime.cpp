#include <iostream>
#include <vector>
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int count_prime_factors(int n) {
    int factors = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            if (is_prime(i)) {
                factors++;
            }
            n /= i;
        }
    }
    return factors;
}

int solve_test_case(int N, int K, const std::vector<int>& A) {
    int left = 0, right = 0;
    int max_length = 0;
    int prime_factors_count = 0;
    int non_prime_factors_count = 0;
    bool prime_factor_in_window = false;

    while (right < N) {
        if (is_prime(A[right])) {
            prime_factors_count++;
            if (prime_factors_count == 2) { 
                prime_factor_in_window = true;
            }
        } else {
            non_prime_factors_count = count_prime_factors(A[right]);
        }

        while (prime_factors_count > 0 || non_prime_factors_count > K || prime_factor_in_window) {
            if (is_prime(A[left])) {
                prime_factors_count--;
                if (prime_factors_count == 1) {
                    prime_factor_in_window = false;
                }
            } else {
                non_prime_factors_count = count_prime_factors(A[left]);
            }
            left++;
        }

        max_length = std::max(max_length, right - left + 1);
        right++;
    }

    return max_length;
}

int main() {
    int T;
    std::cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N, K;
        std::cin >> N >> K;
        std::vector<int> A(N);
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        int result = solve_test_case(N, K, A);
        std::cout << "Case " << caseNum << ": " << result << std::endl;
    }
    return 0;
}