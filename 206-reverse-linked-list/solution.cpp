#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
private:
    ListNode* reverse(ListNode* cur, ListNode* prev)
    {
        if (cur == nullptr)
            return prev;

        ListNode* next = cur->next;
        cur->next = prev;
        return reverse(next, cur);
    }
};


// iterative
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        ListNode *root = nullptr;

        while(head != nullptr)
        {
            s.push(head);
            head = head->next;
        }

        if (!s.empty())
        {
            root = s.top();

            while (!s.empty())
            {
                ListNode *cur = s.top();
                s.pop();
                cur->next = !s.empty() ? s.top() : nullptr;
            }
        }

        return root;
    }
};

// iterative 2
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *cur, *prev, *next, *root;

        root = head;

        cur = head->next;
        prev = head;
        head->next = nullptr;

        while (cur != nullptr)
        {
            next = cur->next;
            if (next == nullptr)
                root = cur;

            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return root;
    }
};

void printList(ListNode* root)
{
    printf("[");
    while (root != nullptr)
    {
        printf("%d ", root->val);
        root = root->next;
    }
    printf("]\n");
}

int main()
{
    Solution3 s;
    ListNode *n = new ListNode(1);
    n->next = new ListNode(2);
    n->next->next = new ListNode(3);
    n->next->next->next = new ListNode(4);

    printList(s.reverseList(n));
    return 0;
}