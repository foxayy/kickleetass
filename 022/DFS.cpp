#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 22. 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 示例：
// 输入：n = 3
// 输出：[
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//      ]
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/generate-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
    int m_n;
public:
    void dfs(vector<string>& res,string str,int l,int r){
        if(l>m_n || r>m_n || r>l)
            return;
        if(l==m_n && r==m_n){
            res.push_back(str);
            return;
        }
        dfs(res,str+"(",l+1,r);
        dfs(res,str+")",l,r+1);
    }
    vector<string> generateParenthesis(int n) {

        m_n = n;
        vector<string> res;
        
        dfs(res,"",0,0);

        return res;
    }
};

int main(int argc, char *argv[])
{	
	Solution s;
    auto res = s.generateParenthesis(3);

    for(auto it:res){
        cout<<it.c_str()<<endl;
    }

	return 0;
}