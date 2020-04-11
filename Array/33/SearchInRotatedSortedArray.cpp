// 
// Created by zengtong on 2020/4/9 11:35 PM.
//

//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//
// 你可以假设数组中不存在重复的元素。
//
// 你的算法时间复杂度必须是 O(log n) 级别。
//
// 示例 1:
//
// 输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
//
//
// 示例 2:
//
// 输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1
// Related Topics 数组 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

static int ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = r - (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 前半部分有序
            if (nums[mid] >= nums[l]) {
                // 往前规约的情况
                if (nums[mid] >= target && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 往后规约的情况
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
