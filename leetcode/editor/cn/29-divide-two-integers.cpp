//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。 
//
// 返回被除数 dividend 除以除数 divisor 得到的商。 
//
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2 
//
// 
//
// 示例 1: 
//
// 输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = truncate(3.33333..) = truncate(3) = 3 
//
// 示例 2: 
//
// 输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = truncate(-2.33333..) = -2 
//
// 
//
// 提示： 
//
// 
// 被除数和除数均为 32 位有符号整数。 
// 除数不为 0。 
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。 
// 
// Related Topics 数学 二分查找 
// 👍 498 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int dividend, int divisor) {
        //边界情况
        if(dividend == divisor) return 1;
        if(divisor == INT_MIN) return 0;

        bool flag = dividend == INT_MIN;
        if(flag) dividend += abs(divisor);

        bool same = dividend >= 0 == divisor >= 0;//是否同正负
        dividend = abs(dividend);//全部转化为正数处理
        divisor = abs(divisor);

        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int temp = dividend >> i;
            res = (res << 1) + (temp >= divisor);
            if(temp >= divisor) dividend -= divisor << i;
        }
        if(flag) return same ? (res != INT_MAX ? res + 1 : res) : -res - 1;
        return same ? res : -res;
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