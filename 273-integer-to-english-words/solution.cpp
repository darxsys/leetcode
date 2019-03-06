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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string number = to_string(num);
        int n = number.size();
        int count = 0;
        string res = "";
        for (int i = n; i > 0; i -= 3)
        {
            string s = i - 3 >= 0 ? number.substr(i-3, 3) : number.substr(0, i);
            if (s.size() == 1)
            {
                res = ones[atoi(s.c_str())] + (hundreds[count] == "" ? "" : " " + hundreds[count]) + (res != "" ? " " + res : "");
            }
            else if (s.size() == 2)
            {
                if (s[0] == '1')
                    res = teens[atoi(s.c_str())] + (hundreds[count] == "" ? "" : " " + hundreds[count]) + (res != "" ? " " + res : "");
                else
                {
                    res = tens[atoi(s.c_str()) / 10 * 10] + (s[1] == '0' ? "" : " " + ones[s[1]-'0']) + (hundreds[count] == "" ? "" : " " + hundreds[count]) + (res != "" ? " " + res : "");
                }
            }
            else
            {
                string first = s[0] == '0' ? "" : ones[s[0]-'0'];
                string rest = "";

                if (s[1] == '0')
                    rest = s[2] != '0' ? ones[s[2] - '0'] : "";
                else if (s[1] == '1')
                    rest = teens[atoi(s.substr(1, 2).c_str())];
                else
                    rest = tens[(s[1]-'0') * 10] + (s[2] == '0' ? "" : " " + ones[s[2] - '0']);

                string r = "";
                if (first != "")
                    r = r + first + " Hundred";

                if (rest != "")
                    r = r != "" ? r + " " + rest : rest; 

                if (r != "")
                    r = r + (hundreds[count] == "" ? "" : " " + hundreds[count]);

                if (r != "")
                    res = r + (res != "" ? " " + res : "");
            }

            count++;
        }

        return res;

    }
private:
    map<int, string> ones = {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
    map<int, string> teens = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
    map<int, string> tens = {{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};

    vector<string> hundreds = {"", "Thousand", "Million", "Billion"};
};


int main()
{
    Solution s;
    // printf("%s\n", s.numberToWords(12).c_str());
    // printf("%s\n", s.numberToWords(123).c_str());
    // printf("%s\n", s.numberToWords(12345).c_str());
    // printf("%s\n", s.numberToWords(1234567).c_str());
    // printf("%s\n", s.numberToWords(1234567891).c_str());
    printf("%s\n", s.numberToWords(123000111).c_str());
    printf("%s\n", s.numberToWords(1012003).c_str());
    printf("%s\n", s.numberToWords(12345).c_str());
    return 0;
}