//给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是 nums[i] 右侧小于 num
//s[i] 的元素的数量。 
//
// 
//
// 示例： 
//
// 输入：nums = [5,2,6,1]
//输出：[2,1,1,0] 
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法 
// 👍 528 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class FenwickTree {
private:
    vector<int> sums;
public:
    FenwickTree(int n) : sums(n + 1, 0) {}

    void update(int i, int delta) {
        while (i < sums.size()) {
            sums[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += sums[i];
            i -= i & -i;
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        set<int> sorted(nums.begin(), nums.end());

        unordered_map<int, int> ranks;
        int rank = 0;
        for (const int sum:sorted)
            ranks[sum] = ++rank;

        vector<int> ans;
        FenwickTree tree(ranks.size());

        for (int i = nums.size() - 1; i >= 0; --i) {
            ans.push_back(tree.query(ranks[nums[i]] - 1));
            tree.update(ranks[nums[i]], 1);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}