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
        if (head == nullptr || head->next == nullptr) return false;
        
        if (head->next->next == nullptr) return false;
        
        ListNode* nextNext = head->next->next;
        
        while (true) {
            if (nextNext == head) return true;
            
            if (nextNext->next == nullptr || nextNext->next->next == nullptr) return false;
            
            nextNext = nextNext->next->next;
            head = head->next;  
        }
        
        return false;
    }
};