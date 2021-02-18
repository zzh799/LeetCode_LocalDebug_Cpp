//我们有一些二维坐标，如 "(1, 3)" 或 "(2, 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。返回所有可能的原始字符串到一个列表
//中。 
//
// 原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001", "00.01"或一些其他更小的数
//来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。 
//
// 最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。 
//
// 
//
// 
//示例 1:
//输入: "(123)"
//输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
// 
//
// 
//示例 2:
//输入: "(00011)"
//输出:  ["(0.001, 1)", "(0, 0.011)"]
//解释: 
//0.0, 00, 0001 或 00.01 是不被允许的。
// 
//
// 
//示例 3:
//输入: "(0123)"
//输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 
//3)"]
// 
//
// 
//示例 4:
//输入: "(100)"
//输出: [(10, 0)]
//解释: 
//1.0 是不被允许的。
// 
//
// 
//
// 提示: 
//
// 
// 4 <= S.length <= 12. 
// S[0] = "(", S[S.length - 1] = ")", 且字符串 S 中的其他元素都是数字。 
// 
//
// 
// Related Topics 字符串 
// 👍 29 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> ambiguousCoordinates(string T) {
        vector<string> res;
        if (T.empty()) {
            return res;
        }

        auto S = T.substr(1, T.size() - 2);
        cout << S << endl;
        int N = S.size();
        for (int i = 1; i < N; i++) {
            auto x = S.substr(0, i);
            auto y = S.substr(i);
            cout << x << " : " << y << endl;
            auto vx = getValidSplits(x);
            auto vy = getValidSplits(y);
            for (const auto& c1 : vx) {
                for (const auto& c2 : vy) {
                    res.push_back("(" + c1 + ", " + c2 + ")");
                }
            }
        }

        return res;
    }

private:
    bool isValidInteger(string str) {
        return str.size() == 1 || str[0] != '0';
    }

    bool isValidDecimal(string str) {
        return str.back() != '0';
    }

    vector<string> getValidSplits(string str) {
        vector<string> res;
        if (isValidInteger(str)) {
            res.push_back(str); // don't add . at all
        }

        for (int i = 1; i < str.size(); i++) {
            auto integer = str.substr(0, i); // prefix zeros have checked before
            auto decimal = str.substr(i);
            if (isValidInteger(integer) && isValidDecimal(decimal)) {
                res.push_back(integer + "." + decimal);
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.ambiguousCoordinates("(123)");
}