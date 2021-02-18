//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,1,4,null,2], k = 1
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：root = [5,3,6,2,4,null,null,1], k = 3
//输出：3
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数为 n 。 
// 1 <= k <= n <= 104 
// 0 <= Node.val <= 104 
// 
//
// 
//
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？ 
// Related Topics 树 二分查找 
// 👍 346 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int i = 1;
    int kk;
    int val = -1;
public:
    int kthSmallest(TreeNode *root, int k) {
        kk = k;
        traverse(root);
        return val;
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) return;
        traverse(root->left);
        if (i == kk) {
            val = root->val;
            return;
        }
        i++;
        traverse(root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    initializer_list<int> data{5, 3, 6, 2, 4, 0, 0, 1};
    Tree *tree = new Tree(data);
    cout << s.kthSmallest(tree->root, 3) << endl;
}