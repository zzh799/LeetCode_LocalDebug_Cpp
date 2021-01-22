//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 进阶： 
//
// 
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
// Related Topics 数组 二分查找 
// 👍 816 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//解答成功: 执行耗时:8 ms,击败了99.43% 的C++用户 内存消耗:13.4 MB,击败了97.32% 的C++用户
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else{
                left = mid;
                right = mid;
                while (left > -1 && nums[left] == target){
                    left--;
                };
                while (right < nums.size() && nums[right] == target){
                    right++;
                };
                res.push_back(left+1);
                res.push_back(right-1);
                return res;
            }
        }
        return {-1, -1};
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{5, 7, 7, 8, 8, 10};
    vector<int> res = s.searchRange(data, 8);
    cout << res[0] << " " << res[1] << endl;

    data = {5, 7, 7, 8, 8, 10};
    res = s.searchRange(data, 6);
    cout << res[0] << " " << res[1] << endl;

    data = {};
    res = s.searchRange(data, 6);
    cout << res[0] << " " << res[1] << endl;

    data = {1};
    res = s.searchRange(data, 1);
    cout << res[0] << " " << res[1] << endl;
}