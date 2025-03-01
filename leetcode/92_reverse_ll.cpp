//https://leetcode.com/problems/reverse-linked-list-ii/
//92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        int temp=1;

        ListNode* start=head;
        ListNode* end;
        ListNode* curr;

        if(left==1) curr =start;
        else{
            while(temp<left-1)
            {   start=start->next;
                temp+=1;
            }
            curr=start->next;
        }
        end=curr;
        ListNode* prev=nullptr;
        ListNode* n;
        if(left!=1) temp+=1;
        while(temp<=right && curr!=nullptr)
        {   n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
            temp+=1;
        }
        end->next=curr;
        if(left==1) return prev;
        start->next=prev;
        return head;
    }


};