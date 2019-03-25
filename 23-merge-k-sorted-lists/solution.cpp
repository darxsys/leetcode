#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        
        vector<int> v;
        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode *head = lists[i];
            while (head != nullptr)
            {
                v.push_back(head->val);
                head = head->next;
            }
        }
        
        if (v.size() == 0) return nullptr;
        
        sort(v.begin(), v.end());
        
        ListNode *head = new ListNode(v[0]);
        ListNode *curr = head;
        for (int i = 1; i < v.size(); ++i)
        {
         curr->next = new ListNode(v[i]);
            curr = curr->next;
        }
        
        return head;
        
    }
};
int main()
{
    return 0;
}