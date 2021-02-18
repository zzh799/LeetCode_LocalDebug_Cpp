//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 示例 1: 
//
// 输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "rat", t = "car"
//输出: false 
//
// 说明: 
//你可以假设字符串只包含小写字母。 
//
// 进阶: 
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
// Related Topics 排序 哈希表 
// 👍 336 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for (int i = 0; i < s.size(); ++i) {
            map1[s[i]]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            map2[t[i]]++;
        }
        for (int j = 0; j < s.size(); ++j) {
            if(map1[s[j]]!=map2[s[j]]) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.isAnagram("anagram", "nagaram") << endl;//1
    cout << s.isAnagram("rat", "car") << endl;//0
}