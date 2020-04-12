// 
// Created by zengtong on 2020/4/12 12:25 AM.
//
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
// 你的算法时间复杂度必须是 O(log n) 级别。
//
// 如果数组中不存在目标值，返回 [-1, -1]。
//
// 示例 1:
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4]
//
// 示例 2:
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1]
// Related Topics 数组 二分查找

//leetcode submit region end(Prohibit modification and deletion)

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

/*
 * 模板
 int binarySearch(int[] nums, int target) {
    int left = 0;
    int right = nums.length - 1; // 左闭右闭区间

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}
 * */

class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        return vector<int>{leftBound(nums, target), rightBound(nums, target)};
    }

private:
    int leftBound(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        // 左闭右闭
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return (left < nums.size() && target == nums[left]) ? left : -1;
    }

    int rightBound(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        // 左闭右闭
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return (right >= 0 && target == nums[right]) ? right : -1;
    }
};


int main() {
    Solution ins;
    auto res = ins.searchRange({5, 7, 7, 8, 8, 10}, 8);
    ostream_iterator<int> out(cout, " ");
    copy(res.begin(), res.end(), out);
    return 0;
}