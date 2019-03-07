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
    void reorderList(ListNode* head) {
        ListNode *cur = head;
        ListNode* left = head;
        ListNode* right = nullptr;
        
        unordered_map<ListNode*, ListNode*> prev;
        prev[head] = nullptr;
        
        while (cur != nullptr)
        {
            right = cur;
            if (cur->next != nullptr)
                prev[cur->next] = cur;
            cur = cur->next;
        }
        
        while (left != right && left->next != right)
        {
            ListNode* next = left->next;
            ListNode* p = prev[right];
            
            if (p)
                p->next = nullptr;
            
            left->next = right;
            right->next = next;
            
            left = next;
            right = p;
        }
    }
};