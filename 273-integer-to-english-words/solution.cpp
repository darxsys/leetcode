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

class Solution2 {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int billion = num / 1000000000;
        int million = (num % 1000000000) / 1000000;
        int thousand = ((num % 1000000)) / 1000;
        int hundred = num % 1000;

        string sol = "";
        string tmp = "";
        three(billion, tmp);
        if (!tmp.empty())
            sol = tmp + " Billion";

        tmp = "";
        three(million, tmp);
        if (!tmp.empty())
        {
            if (!sol.empty())
                sol = sol + " " + tmp + " Million";
            else
                sol = tmp + " Million";
        }

        tmp = "";
        three(thousand, tmp);
        if (!tmp.empty())
        {
            if (!sol.empty())
                sol = sol + " " + tmp + " Thousand";
            else
                sol = tmp + " Thousand";
        }        

        tmp = "";
        three(hundred, tmp);
        if (!tmp.empty())
        {
            if (!sol.empty())
                sol = sol + " " + tmp;
            else
                sol = tmp;
        }

        return sol;
    }
private:
    void three(int num, string& out)
    {
        if (num == 0) return;

        int hundreds = num / 100;
        if (hundreds > 0)
        {
            out = ones(hundreds) + " Hundred";
        }

        int ten = num % 100;
        string tmp = "";
        two(ten, tmp);

        if (!tmp.empty())
        {
            if (!out.empty())
                out = out + " " + tmp;
            else
                out = tmp;
        }
    }

    void two(int num, string& out)
    {
        if (num == 0) return;

        int ten = num / 10;
        if (ten == 1)
        {
            out = teens(num);
        }
        else if (ten == 0)
        {
            out = ones(num);
        }
        else
        {
            out = tens(num / 10);
            if (num % 10 != 0) out = out + " " + ones(num % 10);
        }
    }

    string ones(int num)
    {
        switch (num)
        {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        }

        return "";
    }

    string teens(int num)
    {
        switch (num)
        {
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
        }

        return "";
    }

    string tens(int num)
    {
        switch (num)
        {
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
        }

        return "";
    }
};

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
    Solution2 s;
    printf("%s\n", s.numberToWords(12).c_str());
    printf("%s\n", s.numberToWords(123).c_str());
    printf("%s\n", s.numberToWords(12345).c_str());
    printf("%s\n", s.numberToWords(1234567).c_str());
    printf("%s\n", s.numberToWords(1234567891).c_str());
    printf("%s\n", s.numberToWords(123000111).c_str());
    printf("%s\n", s.numberToWords(1012003).c_str());
    printf("%s\n", s.numberToWords(12345).c_str());
    return 0;
}