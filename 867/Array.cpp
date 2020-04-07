#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 867. 转置矩阵
// 给定一个矩阵 A， 返回 A 的转置矩阵。
// 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

// 示例 1：
// 输入：[[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[1,4,7],[2,5,8],[3,6,9]]
// 示例 2：
// 输入：[[1,2,3],[4,5,6]]
// 输出：[[1,4],[2,5],[3,6]]
//  
// 提示：
//     1 <= A.length <= 1000
//     1 <= A[0].length <= 1000

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/transpose-matrix
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty())
            return {};
        int n=A.size(),m=A[0].size();
        vector<vector<int>> res(m);
        if(n==m){
            res = A;
            for(int i=1;i<n;++i){
                for(int j=0;j<i;++j){
                    swap(res[i][j],res[j][i]);
                }
            }
        }else{
            for(int i=0;i<m;++i){
                vector<int> v(n);
                for(int j=0;j<n;++j){
                    v[j]=A[j][i];
                }
                res[i]=v;
            }
        }
        return res;
    }
};


int main(int argc, char *argv[])
{
	vector<vector<int>> data = { 
          {1,2,3},
          {4,5,6},
          {7,8,9}
    };
	Solution s;
	auto res = s.transpose(data);

	for(auto it:res){
        for(auto d:it){
            cout<<d<<" ";
        }
        cout<<endl;
    }
	cout << endl;
	return 0;
}