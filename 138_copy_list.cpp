//https://leetcode.com/problems/copy-list-with-random-pointer/
//138. Copy List with Random Pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;

        Node* temp=head;
        Node* root;

        while(temp!=NULL)
        {
            if(m.find(temp)!=m.end())
            {
                if(temp->next==NULL) m[temp]->next=NULL;
                else if(m.find(temp->next)!=m.end()) m[temp]->next = m[temp->next];
                else{
                    m[temp->next]=new Node(temp->next->val);
                    m[temp]->next = m[temp->next];
                }

                if(temp->random==NULL) m[temp]->random=NULL;
                else if(m.find(temp->random)!=m.end()) m[temp]->random = m[temp->random];
                else{
                    m[temp->random]=new Node(temp->random->val);
                    m[temp]->random = m[temp->random];
                }
            }
            else{

                m[temp]=new Node(temp->val);
                if(temp->next==NULL) m[temp]->next=NULL;
                else if(m.find(temp->next)!=m.end()) m[temp]->next = m[temp->next];
                else{
                    m[temp->next]=new Node(temp->next->val);
                    m[temp]->next = m[temp->next];
                }
                if(temp->random==NULL) m[temp]->random=NULL;
                else if(m.find(temp->random)!=m.end()) m[temp]->random = m[temp->random];
                else{
                    m[temp->random]=new Node(temp->random->val);
                    m[temp]->random = m[temp->random];
                }

            }
            temp=temp->next;
        }

        return m[head];
    }
};