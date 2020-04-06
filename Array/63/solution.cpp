// 
// Created by zengtong on 2020/4/6 5:27 PM.
//

//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//
//
// 网格中的障碍物和空位置分别用 1 和 0 来表示。
//
// 说明：m 和 n 的值均不超过 100。
//
// 示例 1:
//
// 输入:
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//输出: 2
//解释:
//3x3 网格的正中间有一个障碍物。
//从左上角到右下角一共有 2 条不同的路径：
//1. 向右 -> 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右 -> 向右
//
// Related Topics 数组 动态规划
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &g) {
        int rowLen = g.size() - 1;
        int colLen = g[rowLen].size() - 1;
        if (g.empty() || g[rowLen][colLen] == 1 || g[0][0] == 1) {
            return 0;
        }

        for (int row = 0; row <= rowLen; ++row) {
            for (int col = 0; col <= colLen; ++col) {
                g[row][col] = (g[row][col] == 1 ? -1 : 1);
            }
        }
        search(g);
        return g[0][0];
    }

private:
    void search(vector<vector<int>> &g) {
        for (int row = g.size() - 1; row >= 0; row--) {
            for (int col = g[row].size() - 1; col >= 0; col--) {
                if (g[row][col] < 0 || (row == g.size() - 1 && col == g[row].size() - 1)) {
                    continue;
                }
                long long cur = 0; // int cur = 0; meet this problem: https://leetcode.com/problems/distinct-subsequences/discuss/237641/signed-integer-overflow/236686/
                if (row + 1 < g.size() && g[row + 1][col] != -1) {
                    cur += g[row + 1][col];
                }
                if (col + 1 < g[row].size() && g[row][col + 1] != -1) {
                    cur += g[row][col + 1];
                }
                g[row][col] = cur;
            }
        }
    }
};

int main() {
    vector<vector<int>> in{{0, 0, 0},
                           {0, 1, 0},
                           {0, 0, 0}};
    Solution s;
    int res = s.uniquePathsWithObstacles(in);
    cout << res << endl;
    return 0;
}
//leetcode submit region end(Prohibit modification and deletion)
