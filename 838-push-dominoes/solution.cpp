class Solution {
public:
    string pushDominoes(string dominoes) {
        int lastL = -1;
        int lastR = -1;
        
        int n = dominoes.size();
        
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                if (lastR != -1) {
                    while (++lastR < i) {
                        dominoes[lastR] = 'R';
                    }
                }
                lastR = i;
            } else if (dominoes[i] == 'L') {
                lastL = i;
                if (lastR == -1) {
                    for (int j = i-1; j >= 0 && dominoes[j] == '.'; --j) {
                        dominoes[j] = 'L';
                    }
                } else {
                    int j = i;
                    while (++lastR < --j) {
                        dominoes[lastR] = 'R';
                        dominoes[j] = 'L';
                    }
                    
                    lastR = -1;
                }
            }
        }
        
        if (lastR != -1) {
            while (++lastR < n) {
                dominoes[lastR] = 'R';
            }
        }
        
        return dominoes;
    }
};