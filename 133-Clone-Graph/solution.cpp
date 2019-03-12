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
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> copies;
        Node* new_root = new Node(node->val, node->neighbors);
        queue<Node*> q;
        q.push(new_root);
        copies[node] = new_root;
        
        while (!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            for (int i = 0; i < cur->neighbors.size(); ++i)
            {
                if (copies.find(cur->neighbors[i]) == copies.end())
                {
                    Node* n = new Node(cur->neighbors[i]->val, cur->neighbors[i]->neighbors);
                    q.push(n);
                    copies[cur->neighbors[i]] = n;
                }
                
                cur->neighbors[i] = copies[cur->neighbors[i]];
            }
        }
            
        return new_root;
    }
};

int main()
{
    return 0;
}