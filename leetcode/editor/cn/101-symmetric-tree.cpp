//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 1203 👎 0


#include "include/headers.h"

using namespace LeetCode;
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
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        vector<TreeNode *> stack;
        stack.push_back(root->left);
        stack.push_back(root->right);
        int i = 0;
        while (i < stack.size()) {
            TreeNode *left = stack[i++];
            TreeNode *right = stack[i++];
            if (left == nullptr && right == nullptr) {
                continue;
            } else if (left != nullptr && right != nullptr && left->val == right->val) {
                stack.push_back(left->left);
                stack.push_back(right->right);
                stack.push_back(left->right);
                stack.push_back(right->left);
            } else {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto data = {1, 2, 2, 3, 4, 4, 3};
    auto tree = new Tree(data);

    s.isSymmetric(tree->root);
    auto res = s.isSymmetric(tree->root);
    cout << res << endl;

    data = {1, 2, 2, 0, 3, 0, 3};
    tree = new Tree(data);
    res = s.isSymmetric(tree->root);
    cout << res << endl;

    data = {};
    tree = new Tree(data);
    res = s.isSymmetric(tree->root);
    cout << res << endl;
}