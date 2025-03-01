//2816. Double a Number Represented as a Linked List
//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07

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
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp!=NULL)
        {   temp->val*=2;
            temp=temp->next;
        }
        temp=head->next;
        while(temp!=NULL)
        {   if(temp->val>=10)
            {   prev->val+=1;
                temp->val%=10;
            }
            prev=temp;
            temp=temp->next;
        }
        if(head->val>=10)
        {   prev = new ListNode(1, head);
            head->val%=10;
            return prev;
        }
        return head;
    }
};
