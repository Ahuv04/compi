//https://leetcode.com/problems/sort-list/
//148. Sort List
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* prev;
        ListNode* half=head;
        ListNode* full=head;

        while(full!=NULL && full->next!=NULL)
        {   
            prev=half;
            half=half->next;
            full=full->next->next;
        }
        prev->next=NULL;
        half=sortList(half);
        prev=sortList(head);

        return mergeLists(half,prev);
    }
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode* ans;
        ListNode* temp=nullptr;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                if(temp==NULL)
                {   temp=l1;
                    l1=l1->next;
                    temp->next=NULL;
                    ans=temp;
                }
                else{
                    temp->next=l1;
                    l1=l1->next;
                    temp=temp->next;
                    temp->next=NULL;
                }
            }
            else{
                if(temp==NULL)
                {   temp=l2;
                    l2=l2->next;
                    temp->next=NULL;
                    ans=temp;
                }
                else{
                    temp->next=l2;
                    l2=l2->next;
                    temp=temp->next;
                    temp->next=NULL;
                }
            }
        }
        if(l1!=NULL) temp->next=l1;
        else if(l2!=NULL) temp->next=l2;

        return ans;

    }
};