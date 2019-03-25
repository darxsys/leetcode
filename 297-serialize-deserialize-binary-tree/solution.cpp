#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec2 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        
        string ret = "";
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            
            if (cur == nullptr)
                ret += ret.empty() ? "N" : ",N";
            else
                ret += ret.empty() ? to_string(cur->val) : ',' + to_string(cur->val);
            
            if (cur)
            {
                s.push(cur->right);
                s.push(cur->left);
            }
        }
            
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;

        stringstream datastream(data);
        TreeNode* root = nullptr;
        stack<TreeNode**> s;
        s.push(&root);
        string token;
        
        while (!s.empty())
        {
            TreeNode** cur = s.top();
            s.pop();
            getline(datastream, token, ',');
            
            if (token == "N")
                *cur = nullptr;
            else
                *cur = new TreeNode(stoi(token));
            
            if (*cur)
            {
                s.push(&(*cur)->right);
                s.push(&(*cur)->left);
            }
        }
        
        return root;
    }
};


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        
        string s = "";

        _serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;

        int index = 0;
        return _deserialize(data, &index);
    }
private:
    void _serialize(TreeNode* cur, string& s)
    {
        if (cur == nullptr)
        {
            s.append("N,");
            return;
        }

        s.append(to_string(cur->val));
        s.append(",");

        _serialize(cur->left, s);
        _serialize(cur->right, s);
    }

    TreeNode* _deserialize(const string& data, int* index)
    {
        if (*index >= data.size()) return nullptr;

        int next = data.find(",", *index);
        string val = data.substr(*index, next - *index);
        *index = next+1;

        if (val == "N")
            return nullptr;

        TreeNode* cur = new TreeNode(stoi(val));
        cur->left = _deserialize(data, index);
        cur->right = _deserialize(data, index);

        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* node = new TreeNode(2);
    root->left = node;
    node = new TreeNode(3);
    root->right = node;
    node = new TreeNode(4);
    root->right->left = node;
    node = new TreeNode(5);
    root->right->right = node;
    node = new TreeNode(6);
    root->right->left->left = node;
    node = new TreeNode(7);
    root->right->left->right = node;

    Codec c;
    TreeNode *res = c.deserialize(c.serialize(root));

    assert(res->val == root->val);
    assert(res->left->val == root->left->val);
    assert(res->right->val == root->right->val);
    assert(res->left->left == root->left->left);
    assert(res->right->left->val == root->right->left->val);
    assert(res->right->right->val == root->right->right->val);
    assert(res->right->left->left->val == root->right->left->left->val);
    assert(res->right->left->right->val == root->right->left->right->val);

    return 0;
}