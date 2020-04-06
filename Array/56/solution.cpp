// 
// Created by zengtong on 2020/4/6 4:49 PM.
//

//给出一个区间的集合，请合并所有重叠的区间。
//
// 示例 1:
//
// 输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//
// 示例 2:
//
// 输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
// Related Topics 排序 数组
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compartor);
        auto res = vector<vector<int>>{};
        if (intervals.empty()) {
            return res;
        }

        int i = 0;
        while (i + 1 < intervals.size()) {
            if (!mergeInterval(intervals[i], intervals[i + 1])) {
                res.push_back(intervals[i]);
            }
            ++i;
        }
        // last one
        res.push_back(intervals[i]);
        return res;
    }

private:
    static bool compartor(vector<int> &lhs, vector<int> &rhs) {
        if (lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        } else {
            return lhs[0] < rhs[0];
        }
    }

    static bool isOverlap(vector<int> &lhs, vector<int> &rhs) {
        return lhs[1] >= rhs[0];
    }

    static bool mergeInterval(vector<int> &lhs, vector<int> &rhs) {
        if (isOverlap(lhs, rhs)) {
            rhs[0] = lhs[0];
            rhs[1] = max(lhs[1], rhs[1]);
            return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
