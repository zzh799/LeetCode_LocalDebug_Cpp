//不使用运算符 + 和 - ，计算两整数 a 、b 之和。 
//
// 示例 1: 
//
// 输入: a = 1, b = 2
//输出: 3
// 
//
// 示例 2: 
//
// 输入: a = -2, b = 3
//输出: 1 
// Related Topics 位运算 
// 👍 364 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry =((unsigned int) (a&b))<<1;
            a = a^b;
            b = carry;
        }
        return  a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    cout<<s.getSum(7,1)<<endl;
    cout<<s.getSum(-1,2)<<endl;
    cout<<s.getSum(-1,1)<<endl;
}