//https://leetcode.com/problems/merge-two-sorted-lists/
//21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* root = new ListNode();
        if(list2==NULL) return list1;
        if(list1==NULL) return list2;

        if(list1->val<list2->val)
        {
            ans->val=list1->val;
            list1=list1->next;
        }
        else{
            ans->val=list2->val;
            list2=list2->next;
        }

        root=ans;

        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val)
            {
                ans->next=list1;
                ans=ans->next;
                list1=list1->next;
            }
            else{
                ans->next=list2;
                ans=ans->next;
                list2=list2->next;
            }
        }
        if(list1==NULL) ans->next=list2;
        if(list2==NULL) ans->next=list1;

        return root;   
    }
};