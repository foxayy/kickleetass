#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 面试题13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

// 示例 1：
// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 1：
// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：
//     1 <= n,m <= 100
//     0 <= k <= 20

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//基础图论算法 DFS+递归实现
// res = DFS(x,y) = DFS(x-1,y) + DFS(x+1,y) + DFS(x,y-1) + DFS(x,y+1);//上下左右
class Solution {

    int m_K;
    int m_m;
    int m_n;
    bool** F=nullptr;

public:

    bool lessThanK(int x,int y){
        int k = 0;
        while(x){
            k+=(x%10);
            x/=10;
        }
        while(y){
            k+=(y%10);
            y/=10;
        }
        return k<=m_K;
    }

    bool canInto(int x,int y){
        return x>=0 && x<m_m && y>=0 && y<m_n;
    }

    int DFS(int x,int y){

        if(!canInto(x,y) || !lessThanK(x,y) || F[x][y])
            return 0;

        F[x][y]=1;
        
        return DFS(x-1,y) + DFS(x,y-1) + DFS(x+1,y) + DFS(x,y+1)+1;
    }
    int movingCount(int m, int n, int k) {

        m_K = k;
        m_m = m;
        m_n = n;

        F = new bool*[m];
        for(int i=0;i<m;i++){
            F[i]=new bool[n];
            memset(F[i],0,sizeof(bool)*n);
        }

        int res = DFS(0,0);

        for(int i=0;i<m;i++){
            delete[] F[i];
        }
        delete[] F;
        F = nullptr;

        return res;
    }
};

int main(int argc, char *argv[])
{	
	Solution s;
    cout<<s.movingCount(2,3,1)<<endl;

	return 0;
}