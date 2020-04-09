// 
// Created by zengtong on 2020/4/9 10:18 PM.
//

//给定一个非负整数数组，你最初位于数组的第一个位置。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 判断你是否能够到达最后一个位置。
//
// 示例 1:
//
// 输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
//
//
// 示例 2:
//
// 输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
//
// Related Topics 贪心算法 数组


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.empty()) {
            return true;
        }
        int len = nums.size();
        int closestCanReach = len - 1;
        for (int i = len - 2; i >= 0; --i) {
            int canJump = nums[i];
            // 可直接到最后一个位置 or 可以到最近一个能到最后一个位置的位置
            if (nums[i] + i >= len || i + canJump >= closestCanReach) {
                closestCanReach = i;
            }
        }
        return nums[0] >= closestCanReach;
    }
};

int main() {
    vector<int> in{1, 2, 3};
    auto s = Solution();
    cout << s.canJump(in) << endl;
    return 0;
}
//leetcode submit region end(Prohibit modification and deletion)
