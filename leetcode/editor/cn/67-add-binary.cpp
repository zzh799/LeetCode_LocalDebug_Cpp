//给你两个二进制字符串，返回它们的和（用二进制表示）。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1: 
//
// 输入: a = "11", b = "1"
//输出: "100" 
//
// 示例 2: 
//
// 输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
// Related Topics 数学 字符串 
// 👍 546 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {
        string result ="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0;
        int carry = 0;
        while (i < a.size() && i < b.size()) {
            carry += a[i]=='1' ;
            carry += b[i]=='1';
            result.push_back((carry%2)?'1':'0');
            carry/=2;
            i++;
        }

        while(i<a.size()){
            carry += a[i]=='1' ;
            result.push_back((carry%2)?'1':'0');
            carry/=2;
            i++;
        }
        while(i<b.size()){
            carry += b[i]=='1' ;
            result.push_back((carry%2)?'1':'0');
            carry/=2;
            i++;
        }
        if(carry>0){
            result.push_back('1');
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout<<"Hello LeetCode"<<endl;
}