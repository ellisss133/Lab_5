#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<vector<int>> C = {
        {3, 5, 1, 2},
        {9, 0, 2, 7},
        {4, 8, 6, 3},
        {2, 5, 9, 1}
    };
    
    int rows = C.size();
    int cols = C[0].size();

    int max_sum = INT_MIN, min_sum = INT_MAX;
    int max_row = -1, min_row = -1;

    for (int i = 0; i < rows; i++) {
        int sum = accumulate(C[i].begin(), C[i].end(), 0);

        if (sum > max_sum) {
            max_sum = sum;
            max_row = i;
        }
        if (sum < min_sum) {
            min_sum = sum;
            min_row = i;
        }
    }

    cout << "Matrix C:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Row with the maximum sum: ";
    for (int val : C[max_row]) {
        cout << val << " ";
    }
    cout << "(Sum: " << max_sum << ")" << endl;

    cout << "Row with the minimum sum: ";
    for (int val : C[min_row]) {
        cout << val << " ";
    }
    cout << "(Sum: " << min_sum << ")" << endl;

    return 0;
}