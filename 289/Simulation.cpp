#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 289. 生命游戏
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
// 每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//      如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//      如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//      如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//      如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
// 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
// 示例：
// 输入： 
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// 输出：
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]
// 进阶：
//     你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//     本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/game-of-life
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> L={
        {-1,-1},
        {0,-1},
        {1,-1},
        {1,0},
        {1,1},
        {0,1},
        {-1,1},
        {-1,0}
    };
    int m,n;
    bool location(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    int aliveCeil(const vector<vector<int>>& vv,int x,int y){
        int res=0;
        
        for(int i=0;i<8;i++){
            if(location(x+L[i][0],y+L[i][1])){
                res += vv[x+L[i][0]][y+L[i][1]];
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy(board);
        n = board.size();
        m = board[0].size();

        for(int i=board.size()-1;i>=0;--i){
            for(int j=board[0].size()-1;j>=0;--j){
                int ceil = aliveCeil(copy,i,j);
                if(copy[i][j]){
                    board[i][j]=ceil<2 || ceil >3 ? 0 : 1;
                }else if(ceil == 3){
                    board[i][j]=1;
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
	vector<vector<int>> data = { 
          {0,1,0},
          {0,0,1},
          {1,1,1},
          {0,0,0}
    };
	Solution s;
	s.gameOfLife(data);

	for(auto it:data){
        for(auto d:it){
            cout<<d<<" ";
        }
        cout<<endl;
    }
	cout << endl;
	return 0;
}