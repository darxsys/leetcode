class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (auto& word : words) {
            if (counts.find(word) == counts.end()) {
                counts.emplace(word, 1);
            } else {
                counts.at(word)++;
            }
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, std::function<bool(const pair<int, string>&, const pair<int, string>&)>> q(Compare);
        
        for (auto& [word, count] : counts) {
            if (q.size() == k) {
                auto& topWord = q.top();
                if (topWord.first < count || topWord.first == count && topWord.second > word) {
                    q.pop();
                    q.emplace(pair<int, string>(count, word));
                }
            } else {
                q.emplace(pair<int, string>(count, word));
            }
        }
        
        vector<string> result;
        
        while (!q.empty()) {
            result.push_back(q.top().second);
            q.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
private:
    static bool Compare(const pair<int, string>& left, const pair<int, string>& right) {
        if (left.first != right.first) {
            return left.first > right.first;
        }
        
        return left.second < right.second;
    }
};