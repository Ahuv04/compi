//https://leetcode.com/problems/merge-k-sorted-lists/
//23. Merge k Sorted Lists
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
    ListNode* merge2lists(ListNode* head1, ListNode* head2)
    {
ListNode *temp1 = head1, *temp2 = head2;
    ListNode *fh = NULL, *ft = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val < temp2->val)
        {
            if (fh == NULL)
            {
                fh = temp1;
                ft = temp1;
            }
            else
            {
                ft->next = temp1;
                ft = ft->next;
            }
            temp1 = temp1->next;
        }
        else
        {
            if (fh == NULL)
            {
                fh = temp2;
                ft = temp2;
            }
            else
            {
                ft->next = temp2;
                ft = ft->next;
            }
            temp2 = temp2->next;
        }            
        
    }
        if (temp1 != NULL)
    {
        ft->next = temp1;
    }
    if (temp2 != NULL)
    {
        ft->next = temp2;
    }
    return fh;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {return NULL;}
        else if( lists.size()==1)
        {return lists[0];}
        
        ListNode* ans=merge2lists(lists[0],lists[1]);
        
        for(int i=2;i<lists.size();i++)
        {   ans=merge2lists(ans,lists[i]);
            
        }
        return ans;
    }
};