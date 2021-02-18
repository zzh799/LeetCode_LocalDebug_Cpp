//给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。 
//
// 示例 1: 
//
// 
//输入: [1,2,3]
//输出: 6
// 
//
// 示例 2: 
//
// 
//输入: [1,2,3,4]
//输出: 24
// 
//
// 注意: 
//
// 
// 给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。 
// 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。 
// 
// Related Topics 数组 数学 
// 👍 240 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //一次遍历 o(N)
        int n0=INT32_MIN;
        int n1=INT32_MIN;
        int n2=INT32_MIN;

        int m0=INT32_MAX;
        int m1=INT32_MAX;

        for(int num : nums){
            if(num<m0){
                m1=m0;
                m0=num;
            }else if(num<m1){
                m1=num;
            }

            if(num>n0){
                n2=n1;
                n1=n0;
                n0=num;
            }else if(num>n1){
                n2=n1;
                n1=num;
            }else if(num>n2){
                n2 = num;
            }
        }

        return max(n0*n1*n2,n0*m1*m0);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}