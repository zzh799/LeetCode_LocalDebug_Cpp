### 解题思路
遍历数组，将与val不同的值放入数组前面，并用k作为索引,遇到不同值就自加，最后返回值k即为新数组长

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k= 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
```