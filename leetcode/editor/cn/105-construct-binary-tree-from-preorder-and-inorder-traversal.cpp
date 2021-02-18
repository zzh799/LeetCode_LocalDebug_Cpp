//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 874 👎 0


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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()||inorder.empty())
            return  nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        int i;
        for (i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        vector<int> pre(preorder.begin()+1, preorder.begin() + i+1 );
        vector<int> in(inorder.begin(), inorder.begin() + i );
        root->left = buildTree(pre,in);

        vector<int> pre2(preorder.begin()+i+1, preorder.end());
        vector<int> in2(inorder.begin()+i+1, inorder.end());
        root->right = buildTree(pre2,in2);

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> pre{3, 9, 20, 15, 7};
    vector<int> in{9,3,15,20,7};
    Tree *tree = new Tree({});
    tree->root = s.buildTree(pre, in);
    tree->print();

}