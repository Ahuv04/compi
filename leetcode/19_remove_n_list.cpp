//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* k=head;
        int t=0;

        while(k!=NULL)
        {   k=k->next;
            t+=1;
        }
        int p=1;

        if(n==t)
        {   return head->next;}

        k=head;
        while(k!=NULL)
        {   if(p+n>=t)
            {   
                k->next=k->next->next;
                break;
            }
            k=k->next;
            p+=1;
        }
        return head;
    }
};