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
class Comp{
public:
    bool operator()(pair<int, ListNode*> &a, pair<int, ListNode*> &b){
        return a.first > b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Comp> minHeap;

        for(ListNode* curr: lists){
            if(curr != nullptr){
                minHeap.push({curr->val, curr});
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* h = dummy;

        while(!minHeap.empty()){
            auto t = minHeap.top();
            minHeap.pop();
            auto curr = t.second;
            h->next = curr;
            h = h->next;

            if(curr->next != nullptr){
                minHeap.push({curr->next->val, curr->next});
            }
        }

        return dummy->next;
    }
};