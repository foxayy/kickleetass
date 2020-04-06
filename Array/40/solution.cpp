// 
// Created by zengtong on 2020/4/6 2:46 PM.
//

//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用一次。
//
// 说明：
//
//
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1:
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//
//
// 示例 2:
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//]
// Related Topics 数组 回溯算法
#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;

        set<vector<int>> res;
        vector<int> arr;
        dfs(res, 0, arr, target);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    vector<int> candidates;
private:
    void dfs(set<vector<int>> &res, int pos, vector<int> &arr, int target) {
        if (target == 0) {
            res.insert(arr);
            return;
        } else if (pos >= this->candidates.size()) {
            return;
        } else if (target < 0) {
            return;
        }

        arr.push_back(this->candidates[pos]);
        dfs(res, pos + 1, arr, target - this->candidates[pos]);
        arr.pop_back();
        while (pos < this->candidates.size() - 1 && this->candidates[pos] == this->candidates[pos + 1]) {
            ++pos;
        }
        dfs(res, pos + 1, arr, target);
    }
};

int main() {
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    auto res = Solution().combinationSum2(candidates, target);
}
//leetcode submit region end(Prohibit modification and deletion)
