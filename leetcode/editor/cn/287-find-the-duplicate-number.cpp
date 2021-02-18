//给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。 
//
// 假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。 
//
//
//
// 示例 1： 
//
// 
//输入：nums = [1,3,4,2,2]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,1,3,4,2]
//输出：3
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1]
//输出：1
// 
//
// 示例 4： 
//
// 
//输入：nums = [1,1,2]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 2 <= n <= 3 * 104 
// nums.length == n + 1 
// 1 <= nums[i] <= n 
// nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次 
// 
//
// 
//
// 进阶： 
//
// 
// 如何证明 nums 中至少存在一个重复的数字? 
// 你可以在不修改数组 nums 的情况下解决这个问题吗？ 
// 你可以只用常量级 O(1) 的额外空间解决这个问题吗？ 
// 你可以设计一个时间复杂度小于 O(n2) 的解决方案吗？ 
// 
// Related Topics 数组 双指针 二分查找 
// 👍 1067 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        mysort(nums, 0, nums.size() - 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[i + 1]) return nums[i];
        }
        return 0;
//        int low = 1;
//        int up = nums.size() - 1;
//
//        while (low < up) {
//            int mid = low + (up - low + 1) / 2;
//            int count =0;
//            for (int num:nums) {
//                if(num<mid){
//                    count++;
//                }
//            }
//            if(count>=mid){
//                up=mid-1;
//            }else{
//                low = mid;
//            };
//
//        }
//
//        return low;
    }

    void mysort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int l = left;
        int r = right;
        int pivot = nums[l];
        while (l < r) {
            while (l < r && pivot<= nums[r])r--;
            if (l < r) nums[l++] = nums[r];
            while (l < r && pivot> nums[l])l++;
            if (l < r) nums[r--] = nums[l];
        }
        nums[l] = pivot;
        mysort(nums, left, l - 1);
        mysort(nums, r + 1, right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 3, 4, 2, 2};
    cout << s.findDuplicate(data) << endl;//2
    data = {3, 1, 3, 4, 2};
    cout << s.findDuplicate(data) << endl;//3
    data = {1, 1};
    cout << s.findDuplicate(data) << endl;//1
}