//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 深度优先搜索 递归 字符串 回溯算法 
// 👍 1082 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string tmp;
    vector<string> res;
    vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void DFS(int pos, string digits) {
        if (pos == digits.size()) {
            res.push_back(tmp);
            cout<<tmp<<endl;
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < board[num].size(); i++) {
            tmp.push_back(board[num][i]);
            DFS(pos + 1, digits);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        DFS(0, digits);
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> a = s.letterCombinations("222");
//    for (string s :a) {
//        cout << s << endl;
//    }
}