//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 示例: 
//
// 输入: [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
// Related Topics 动态规划 
// 👍 661 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int dp_i_0 = 0;
        int dp_i_i = INT_MIN;
        int dp_pre_0 = 0;
        for (int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_i + prices[i]);
            dp_i_i = max(dp_i_i,dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{3, 3, 5, 0, 0, 3, 1, 4};//6
    cout << s.maxProfit(data) << endl;

    data = {1, 2, 3, 4, 5};//4
    cout << s.maxProfit(data) << endl;

    data = {7, 6, 4, 3, 1};//0
    cout << s.maxProfit(data) << endl;

    data = {1};//0
    cout << s.maxProfit(data) << endl;

    data = {2,1,2,0,1};//2
    cout << s.maxProfit(data) << endl;
}