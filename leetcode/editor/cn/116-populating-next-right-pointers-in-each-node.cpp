//给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下： 
//
// 
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//} 
//
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
// 初始状态下，所有 next 指针都被设置为 NULL。 
//
// 
//
// 进阶： 
//
// 
// 你只能使用常量级额外空间。 
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。 
// 
//
// 
//
// 示例： 
//
// 
//
// 
//输入：root = [1,2,3,4,5,6,7]
//输出：[1,#,2,3,#,4,5,6,7,#]
//解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 
//next 指针连接，'#' 标志着每一层的结束。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数量少于 4096 
// -1000 <= node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 394 👎 0


#include "include/headers.h"

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    queue<Node *> queue;
public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;
        int count = 1;
        int i = 0;
        queue.push(root);
        while (!queue.empty()) {
            if (i == count - 1) {
                Node *p = queue.front();
                if (p->left != nullptr)queue.push(p->left);
                if (p->right != nullptr)queue.push(p->right);
                queue.pop();
                count *= 2;
                i = 0;
            } else {
                Node *p = queue.front();
                if (p->left != nullptr)queue.push(p->left);
                if (p->right != nullptr)queue.push(p->right);
                queue.pop();
                p->next = queue.front();
                i++;
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    Node *n7 = new Node(7);
    Node *n6 = new Node(6);
    Node *n5 = new Node(5);
    Node *n4 = new Node(4);
    Node *n3 = new Node(3);
    Node *n2 = new Node(2);
    Node *n1 = new Node(1);

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    n1->left = n2;
    n1->right = n3;

    cout << s.connect(n1) << endl;
}