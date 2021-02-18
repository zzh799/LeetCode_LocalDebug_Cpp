//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 104] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 设计 
// 👍 473 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)    return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        string tree = to_string(root->val) + "," + left + "," + right;
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* decode(queue<string>& data) {
        if (data.empty())   return nullptr;
        string ch = data.front();
        data.pop();
        if (ch == "#")  return nullptr;
        TreeNode* root = new TreeNode(stoi(ch));
        root->left = decode(data);
        root->right = decode(data);
        return root;
    }
    //字符串转列表
    queue<string> stringToList(string& data) {
        queue<string> que;
        int i = 0, j = 0;
        while (i < data.size()) {
            while (i < data.size() && data[i] == ',')  ++i;
            int cnt = 0;
            while (i + cnt < data.size() && data[i + cnt] != ',')  ++cnt;
            if (i + cnt <= data.size()) {
                string tmp = data.substr(i,cnt);
                que.push(tmp);
            }
            i = i + cnt;
        }
        return que;
    }
    TreeNode* deserialize(string data) {
        queue<string> que = stringToList(data);
        return decode(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Codec s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout<<"Hello LeetCode"<<endl;
}