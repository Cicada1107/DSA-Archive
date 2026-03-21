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
        if(head == nullptr || head->next == nullptr) return false;
        ListNode* curr = head;
        ListNode* aux = head->next;
        while(aux != nullptr && aux->next != nullptr){
            if(curr == aux) return true;
            curr = curr->next;
            aux = aux->next->next;
        }
        return false;
    }
};