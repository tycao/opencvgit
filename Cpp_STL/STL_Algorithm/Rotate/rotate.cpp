#include <algorithm>
#include "rotate.h"

using namespace std;

void Solution::rotate(std::vector<std::vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (decltype(matrix.size()) i = 0; i < matrix.size(); ++i) {
        for (decltype(matrix.size()) j = i; j < matrix[i].size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
