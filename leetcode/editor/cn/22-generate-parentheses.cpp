//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 回溯算法 
// 👍 1559 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return {"()"};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const string& p:dp[j]) {
                    for (const string& q:dp[i - j - 1]) {
                        dp[i].emplace_back("(" + p + ")" + q);
                    }
                }
            }
        }
        return dp[n];
    }

    void printV(vector<string> v){
        for(string i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};
//leetcode submit region end(Prohibit modification and deletion)



int main() {
    Solution s;

    s.printV(s.generateParenthesis(3));
}

