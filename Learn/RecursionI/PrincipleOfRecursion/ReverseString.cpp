// 
// Created by zengtong on 2020/4/13 10:52 PM.
//

//Write a function that reverses a string. The input string is given as an array
// of characters char[].
//
// Do not allocate extra space for another array, you must do this by modifying
//the input array in-place with O(1) extra memory.
//
// You may assume all the characters consist of printable ascii characters.
//
//
//
//
// Example 1:
//
//
//Input: ["h","e","l","l","o"]
//Output: ["o","l","l","e","h"]
//
//
//
// Example 2:
//
//
//Input: ["H","a","n","n","a","h"]
//Output: ["h","a","n","n","a","H"]
//
//
//
// Related Topics Two Pointers String
#include <vector>
#include <iostream>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reverseString(vector<char> &s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            Swap(s, l, r);
            ++l;
            --r;
        }
    }
private:
    void Swap(vector<char>&s, int lhs, int rhs) {
        auto tmp = s[lhs];
        s[lhs] = s[rhs];
        s[rhs] = tmp;
    }
};

int main() {
    auto in = vector<char>{'h','e','l','l','o'};
    Solution().reverseString(in);
    ostream_iterator<char> out(cout, " ");
    copy(in.begin(), in.end(), out);
    return 0;
}
//leetcode submit region end(Prohibit modification and deletion)
