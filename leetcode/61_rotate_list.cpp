//https://leetcode.com/problems/rotate-list/
//61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int p) {
        if(p==0) return head;

        int t=0;
        ListNode* k=head;

        while(k!=NULL)
        {   t+=1;
            if(k->next==NULL)
            {   
                break;
            }
            k=k->next;
        }

        if(t==0) return head;

        p=p%t;
        if(p==0) return head;
        k->next=head;

        k = head;
        ListNode* prev=nullptr;
        while(t!=p)
        {   t-=1;
            prev=k;
            k=k->next;
        }
        prev->next=nullptr;
        return k;
    }
};