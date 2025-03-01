// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/?envType=daily-question&envId=2024-05-05
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(true)
        {   swap(node->next->val, node->val);
            if(node->next->next==NULL)
            {
                node->next=NULL;
                break;
            }
            node=node->next;
        }
        return;
    }
};
