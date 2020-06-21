#include <string>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        std::vector<std::string> serialized;
        serializeInternal(root, serialized);
        string result;
        for (auto&& str : serialized) {
            result.append(str);   
        }
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        Deser state;
        state.data = std::string_view(data.c_str(), data.size());
        return deserializeInternal(state);
    }
    
private:
    struct Deser {
        std::string_view data;
        size_t ptr = 0;
    };

    void serializeInternal(TreeNode* root, std::vector<std::string>& serialized) {
        serialized.push_back(std::to_string(root->val));
        serialized.push_back(kDelimiter);
        
        if (root->left) {
            serializeInternal(root->left, serialized);     
        } else {
            serialized.push_back(kDelimiter);
        }
        
        if (root->right) {
            serializeInternal(root->right, serialized);
        } else {
            serialized.push_back(kDelimiter);
        }
    };
    
    TreeNode* deserializeInternal(Deser& state) {
        if (state.ptr >= state.data.size()) return nullptr;
        
        auto delim = state.data.find(kDelimiter, state.ptr);
        if (delim - state.ptr == 0) {
            state.ptr++;
            return nullptr;
        }
        
        int val;
        std::from_chars(state.data.data()+state.ptr, state.data.data()+state.ptr+delim, val);
        
        TreeNode* node = new TreeNode(val);
        state.ptr = delim+1;
        node->left = deserializeInternal(state);
        node->right = deserializeInternal(state);
        return node;
    }
    
    const string kDelimiter = ";";
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    return 0;
}