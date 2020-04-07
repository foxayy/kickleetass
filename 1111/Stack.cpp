#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;


// 1111. 有效括号的嵌套深度
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 题解参考链接：https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/you-xiao-gua-hao-de-qian-tao-shen-du-by-leetcode-s
class Solution {
public:

	vector<int> maxDepthAfterSplit(string seq) {
		int d = 0,i=0;
        vector<int> ans(seq.size());
        for (const char& c : seq)
            if (c == '(') {
                ++d;
                ans[i++]=d % 2;
            }
            else {
                ans[i++]=d % 2;
                --d;
            }
        return ans;
	}
};

int main(int argc, char *argv[])
{
    string data=  "(()())";

    Solution s;
    auto res = s.maxDepthAfterSplit(data);

    for(auto it = res.begin();it!=res.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
