//2487. Remove Nodes From Linked List
//https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06

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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* temp=head;
        while(temp!=NULL){
            while(!stack.empty())
            {   if(stack.top()->val>=temp->val)
                {   stack.top()->next=temp;
                    stack.push(temp);
                    break;
                }
                else{
                    stack.pop();
                }
            }
            if(stack.empty())
            {   stack.push(temp);
                head=temp;
            }
            temp=temp->next;
        }
        // while(!stack.empty())
        // {
        //     temp=stack.top();
        //     stack.pop();
        // }
        return head;
    }
};
