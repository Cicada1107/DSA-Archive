/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        set<ListNode*> s;
        s.insert(head);
        while(curr != nullptr){
            if(curr->next != nullptr && s.find(curr->next) != s.end()) return true;
            s.insert(curr->next);
            curr = curr->next;
        }
        return false;
    }
};