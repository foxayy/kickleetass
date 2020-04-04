// 
// Created by zengtong on 2020/4/1 12:19 AM.
//

//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
// 说明：每次只能向下或者向右移动一步。
//
// 示例:
//
// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
//
// Related Topics 数组 动态规划

//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        this->xlast = grid.size() - 1;
        this->ylast = grid[0].size() - 1;
        this->mem = vector<vector<int>>(xlast + 1, vector<int>(ylast + 1, -1));
        return dp(grid, 0, 0);
    }

    int dp(vector<vector<int>> &grid, int x, int y) {
        if (x <= xlast && y <= ylast && mem[x][y] != -1) {
            return mem[x][y];
        }

        if (x == this->xlast && y == this->ylast) {
            return grid[x][y];
        } else if (x >= this->xlast) {
            return grid[x][y] + dp(grid, x, y + 1);
        } else if (y >= this->ylast) {
            return grid[x][y] + dp(grid, x + 1, y);
        }
        int res = grid[x][y] + min(dp(grid, x, y + 1), dp(grid, x + 1, y));
        mem[x][y] = res;
        return res;
    }

private:
    int xlast;
    int ylast;
    vector<vector<int>> mem;
};

int main() {
    auto grid = vector<vector<int>>{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
//leetcode submit region end(Prohibit modification and deletion)
