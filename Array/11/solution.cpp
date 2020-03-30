// 
// Created by zengtong on 2020/3/30 10:17 PM.
//

//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i,
//ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
// 说明：你不能倾斜容器，且 n 的值至少为 2。
//
//
//
//
//
// 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//
//
//
// 示例：
//
// 输入：[1,8,6,2,5,4,8,3,7]
//输出：49
// Related Topics 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int res = 0;
        while (l < r) {
            res = max(res, (r - l)*min(h[r], h[l]));
            h[r] > h[l] ? l++ : r--;
        }
        return res;
    }
};
/*
 * O(N^2) [1,2,3,4,5,6,7]
class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxV = 0;
        int preMaxH = -1;
        for (int i = 0; i < h.size(); ++i) {
            if (preMaxH > h[i]) {
                continue;
            } else {
                preMaxH= max(preMaxH, h[i]);
            }
            for (int j = i + 1; j < h.size(); ++j) {
                maxV = max(abs(i-j)*min(h[i],h[j]), maxV);
            }
        }
        return maxV;
    }
};

*/
//leetcode submit region end(Prohibit modification and deletion)
