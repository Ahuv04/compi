//https://leetcode.com/problems/partition-list/description/
//86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> v;

        ListNode* temp=head;

        ListNode* prev=nullptr;
        ListNode* ans;
        ListNode* last;

        ListNode* v2=nullptr;
        ListNode* v1=nullptr;

        while(temp!=NULL)
        {   if(temp->val<x)
            {   if(prev==NULL)
                {   prev=temp;
                    ans=temp;
                }
                else{
                    prev->next=temp;
                    prev=temp;
                    if(temp->next==NULL) break;
                }
                temp=temp->next;
            }
            else{
                if(v1==NULL) {
                    v1=temp;
                    temp=temp->next;
                    v1->next=NULL;
                }
                else{
                    if(v2==NULL) 
                    {
                        v2=temp;
                        v1->next=v2;
                        temp=temp->next;
                        v2->next=NULL;
                    }
                    else{
                        v2->next=temp;
                        v2=temp;
                        temp=temp->next;
                        v2->next=NULL;
                    }
                }
            }
        }
        if(prev==NULL) return v1;

        prev->next=v1;

        return ans;
    }
};