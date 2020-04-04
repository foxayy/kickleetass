// 
// Created by zengtong on 2020/4/4 11:16 PM.
//

//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
// 必须原地修改，只允许使用额外常数空间。
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
/* [1,5,8,4,7,6,5,3,1] => [1,5,8,5,1,3,4,6,7]
 * 从后往前遍历，找出第 K 个元素满足 num[k] < num[k+1].
 * 1. 如果 K < 0 ，则其本身就已经是最大序列。
 * 2. K >= 0,
 *      2.1 再往后遍历找到第J位，num[k] >= num[j], 交换位置: swap(num[k], num[j - 1]).
 *      2.2 sort(num, j, nums.size()-1)
 * */
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int k = nums.size() - 2;
        // 找到k
        while (k >= 0 && nums[k] >= nums[k + 1]) {
            --k;
        }
        if (k < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        // 找其后比第k位大的最小值
        int j = k + 1;
        while (j < nums.size() && nums[k] < nums[j]) {
            ++j;
        }
        swap(nums, j - 1, k);
        sort(nums.begin() + k + 1, nums.end());
    }

private:
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
