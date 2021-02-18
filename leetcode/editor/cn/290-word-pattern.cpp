//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。 
//
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。 
//
// 示例1: 
//
// 输入: pattern = "abba", str = "dog cat cat dog"
//输出: true 
//
// 示例 2: 
//
// 输入:pattern = "abba", str = "dog cat cat fish"
//输出: false 
//
// 示例 3: 
//
// 输入: pattern = "aaaa", str = "dog cat cat dog"
//输出: false 
//
// 示例 4: 
//
// 输入: pattern = "abba", str = "dog dog dog dog"
//输出: false 
//
// 说明: 
//你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。 
// Related Topics 哈希表 
// 👍 305 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> ss = split(s, ' ');
        if (pattern.size() != ss.size()) return false;
        for (int i = 0; i < pattern.size(); ++i) {
            if (map1.find(pattern[i]) == map1.end()) {
                map1[pattern[i]] = ss[i];
            }
            if (map2.find(ss[i]) == map2.end()) {
                map2[ss[i]] = pattern[i];
            }
            if (map1[pattern[i]] != ss[i] || map2[ss[i]] != pattern[i]) return false;

        }
        return true;
    }

    void SplitString(const std::string &s, std::vector<std::string> &v, const std::string &c) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while (std::string::npos != pos2) {
            v.push_back(s.substr(pos1, pos2 - pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

    vector<string> split(string s, char c) {
        int pos1 = 0;
        int pos2 = s.find(c);
        vector<string> v;
        while (pos2 != -1) {
            v.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + 1;
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length()) {
            v.push_back(s.substr(pos1));
        }
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

    cout << s.wordPattern("abba", "dog cat cat dog") << endl;//1
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;//0
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;//0
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;//0
}