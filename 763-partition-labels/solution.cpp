class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {};
        
        int start = 0;
        int end = 0;
        vector<int> ret;
        
        vector<int> maxIndex(26);
        for (int i = 0; i < S.size(); ++i) {
            maxIndex[S[i]-'a'] = i;
        }
        
        while (start < S.size()) {
            // find end for current character
            end = maxIndex[S[start]-'a'];
            
            for (int i = start + 1; i <= end; ++i) {
                end = max(end, maxIndex[S[i]-'a']);
            }
            
            ret.push_back(end - start + 1);
            start = end + 1;
            end = end + 1;
        }
        
        return ret;
    }
};

int main() {
	return 0;
}
