class Solution {
public:
    int numSplits(string s) {
        if (s.empty() || s.size() == 1) return 0;
        
        int ret = 0;
        vector<bool> seenfromStart(30, false);
        vector<bool> seenfromEnd(30, false);
        vector<int> countFromStart(s.size(), 0);
        vector<int> countFromEnd(s.size(), 0);
        
        int start = 1;
        seenfromStart[s[0] - 'a'] = true;
        seenfromEnd[s.back()-'a'] = true;
        countFromStart[0] = 1;
        countFromEnd[s.size()-1] = 1;
        int end = s.size()-2;
        
        int counterFromStart = 1;
        int counterFromEnd = 1;
        while (start < s.size()) {
            if (!seenfromStart[s[start]-'a']) {
                counterFromStart++;
                seenfromStart[s[start]-'a'] = true;
            }
            if (!seenfromEnd[s[end]-'a']) {
                counterFromEnd++;
                seenfromEnd[s[end]-'a'] = true;
            }
            
            countFromStart[start++] = counterFromStart;
            countFromEnd[end--] = counterFromEnd;
        }
        
        for (int i = 0; i < s.size()-1; ++i) {
            if (countFromStart[i] == countFromEnd[i+1]) ret++;
        }
        
        return ret;
    }
};

int main() {
	return 0;
}
