//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。 
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。 
// 你可以按任意顺序返回答案。 
// 
// Related Topics 堆 哈希表 
// 👍 636 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

public:
    static bool cmp(pair<int,int> &m,pair<int,int> &n){
        return m.second>n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occur;
        for (int i = 0; i < nums.size(); ++i) {
            occur[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(&cmp)> q(cmp);
        for(auto [num,count]:occur){
            if(q.size()==k){
                if(q.top().second<count){
                    q.pop();
                    q.emplace(num,count);
                }
            }else{
                q.emplace(num,count);
            }
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,1,1,2,2,3};

    cout<<s.topKFrequent(data,2).size()<<endl;
}