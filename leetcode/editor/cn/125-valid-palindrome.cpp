//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 说明：本题中，我们将空字符串定义为有效的回文串。 
//
// 示例 1: 
//
// 输入: "A man, a plan, a canal: Panama"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "race a car"
//输出: false
// 
// Related Topics 双指针 字符串 
// 👍 324 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j = s.size()-1;
        while(i<=j){
            int ci =isLetter(s[i]);
            int cj =isLetter(s[j]);
            if(!ci){
                i++;
                continue;
            }
            if(!cj){
                j--;
                continue;
            }
            if(ci==cj){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }

    int isLetter(char c) {
        int res = 0;
        if (c >= 'A' && c <= 'Z') res = c + 'a'-'A';
        else if (c >= 'a' && c <= 'z') res = c;
        else if (c >= '0' && c <= '9') res = c;

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;//true
    cout << s.isPalindrome("race a car") << endl;//false
    cout << s.isPalindrome("") << endl;//false
    cout << s.isPalindrome("a") << endl;//true

}