#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double find_minimal_area(vector<pair<int, int>>& fireflies) {
    sort(fireflies.begin(), fireflies.end());

    int min_x = fireflies[0].first;
    int max_x = fireflies.back().first;
    int max_y = 0;

    for (const auto& ff : fireflies) {
        max_y = max(max_y, ff.second);
    }

    double rectangle_area = static_cast<double>(max_x - min_x) * max_y;
    double triangle_area = static_cast<double>(max_x - min_x) * (max_x - min_x) / 2.0;

    return triangle_area / (2.0 * rectangle_area);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> fireflies;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            fireflies.push_back({x, y});
        }

        double result = find_minimal_area(fireflies);
        cout << fixed << setprecision(7) << result << endl;
    }

    return 0;
}