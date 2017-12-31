#include "solution.h"

using std::vector;

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> vec{{0,2,1,5,2,6,9},{3,5,4,7,4,3,8},{6,9,3,8,5,7,0}};
    s.minPathSum(vec);

    return 0;
}
