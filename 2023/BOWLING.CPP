#include <iostream>
#include <string>
using namespace std;
void calculate_bowling_figures(string S) {
    int overs = S.length() / 6;
    int remaining_balls = S.length() % 6;
    int runs = 0;
    int wickets = 0;

    for (char ball : S) {
        if (ball == 'W') {
            wickets++;
        } else {
            runs += (ball - '0');
        }
    }

    cout << overs << "." << remaining_balls << " Overs " << runs << " Runs " << wickets << " Wicket(s)." << endl;
}
int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string S;
        cin >> S;
        calculate_bowling_figures(S);
    }

    return 0;
}