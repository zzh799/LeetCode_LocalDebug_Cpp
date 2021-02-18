//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 示例: 
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶: 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 2816 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划1
//        int max_sum = nums[0];
//        int cur_sum = nums[0];
//
//        for (int i = 1; i < nums.size(); ++i) {
//            cur_sum = max(nums[i],cur_sum+nums[i]);
//            max_sum = max(cur_sum,max_sum);
//        }
//        return max_sum;

//动态规划2
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i-1]>0){
                nums[i]+=nums[i-1];
            }
        }
        return  *max_element(nums.begin(),nums.end());
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