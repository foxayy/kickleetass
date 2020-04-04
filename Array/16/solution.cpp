// 
// Created by zengtong on 2020/4/1 11:21 PM.
//

//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。
//
// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
//
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
//
// Related Topics 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <algorithm>

using namespace std;

// 每次移动使得 gap 尽量小
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[nums.size() - 1];
        int minDistance = abs(res - target);
        for (int i = 0 ; i < nums.size() - 2; ++i) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                sum > target ? --end : ++ start;
                if (sum == target) {
                    return sum;
                } else if (abs(sum-target) < minDistance) {
                    minDistance = abs(sum-target);
                    res = sum;
                }
            }
        }
        return res;
    }
};
/*
 *
 *
 * 暴力
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        int closest = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int z = j + 1; z < nums.size(); ++z) {
                    int gap = abs(nums[i] + nums[j] + nums[z] - target);
                    if (gap <= closest) {
                        sum = nums[i] + nums[j] + nums[z];
                        closest = gap;
                    }
                }
            }
        }
        return sum;
    }
};*/
//leetcode submit region end(Prohibit modification and deletion)
