#include <cstdio>
#include <cstring>
#include <climits>
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
#include <unordered_set>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> lookup;
        
        Node* cur = head;
        Node* prev = nullptr;
        Node *n;
        while (cur != nullptr)
        {
            n = new Node();
            if (prev)
                prev->next = n;
            n->val = cur->val;
            n->next = nullptr;
            prev = n;
            lookup[cur] = n;
            cur = cur->next;
        }
        
        cur = head;
        Node* head2 = lookup[head];
        while (cur != nullptr)
        {
            n = lookup[cur];
            n->random = lookup[cur->random];
            cur = cur->next;
        }
        
        return head2;
    }
};

int main()
{
    return 0;
}