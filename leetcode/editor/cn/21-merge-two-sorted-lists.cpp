//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
// Related Topics 递归 链表 
// 👍 1488 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* newlist2 = new ListNode(0);
        ListNode* newlist = newlist2;

        while(p!=NULL&&q!=NULL){
            if(p->val<q->val){
                newlist->next=p;
                p=p->next;
                newlist=newlist->next;
            }else if(p->val>q->val){
                newlist->next=q;
                q=q->next;
                newlist=newlist->next;
            }else{
                newlist->next=p;
                p=p->next;
                newlist=newlist->next;
                newlist->next=q;
                q=q->next;
                newlist=newlist->next;
            }
        }
        while(p!=NULL){
            newlist->next=p;
            p=p->next;
            newlist=newlist->next;
        }
        while(q!=NULL){
            newlist->next=q;
            q=q->next;
            newlist=newlist->next;
        }
        return newlist2->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout<<"Hello LeetCode"<<endl;
}