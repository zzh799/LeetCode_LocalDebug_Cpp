//给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。 
//
// 列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。 
//
// 
//
// 示例 1: 
//
// 输入: [[1,1],2,[1,1]]
//输出: [1,1,2,1,1]
//解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。 
//
// 示例 2: 
//
// 输入: [1,[4,[6]]]
//输出: [1,4,6]
//解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
// 
// Related Topics 栈 设计 
// 👍 195 👎 0


#include "include/headers.h"

using namespace std;


class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

//leetcode submit region begin(Prohibit modification and deletion)


class NestedIterator {
public:
    stack<NestedInteger> list;

    NestedIterator(vector<NestedInteger> &nestedList) {
        pushList(nestedList);
    }

    void pushList(const vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i > -1; --i) {
            list.push(nestedList[i]);
        }
    }

    int next() {
        int res = list.top().getInteger();
        list.pop();
        return res;
    }

    bool hasNext() {
        while (!list.empty()&&!list.top().isInteger()) {
            NestedInteger ni = list.top();
            list.pop();
            pushList(ni.getList());
        }
        return !list.empty();
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {

}