// 24. Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* currhead=head;
        ListNode* ghead=head;
        ListNode* tghead;
        ListNode* prev;

        if(ghead==NULL || ghead->next==NULL)
        {
            return ghead;
        }
        else{
            currhead=ghead->next->next;
            ghead->next->next=head;
            ghead=head->next;
            head->next=currhead;
            prev=head;
        }
        while(currhead!=NULL && currhead->next!=NULL)
        {   cout<<currhead->val<<endl;
            tghead=currhead;
            head=currhead;
            currhead=tghead->next->next;
            tghead->next->next=head;
            tghead=head->next;
            head->next=currhead;
            prev->next=tghead;
            prev=head;
        }
        return ghead;
    }
};
