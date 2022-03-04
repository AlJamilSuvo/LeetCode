#include <bits/stdc++.h>
using namespace std;
/*
"Zero"
"One"
"Two"
"Three"
"Four"
"Five"
"Six"
"Seven"
"Eight"
"Nine"
"Ten"
"Eleven"
"Twelve"
"Thirteen"
"Fourteen"
"Fifteen"
"Sixteen"
"Seventeen"
"Eighteen"
"Nineteen"
"Twenty"

"Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven"


"Ten"
"Twenty"
"Thirty"
"Forty"
"Fifty"
"Sixty"
"Seventy"
"Eighty"
"Ninety"


*/

class Solution
{
    vector<string> names = {"", "Thousand", "Million", "Billion"};
    vector<string> digits = {"", "One", "Two", "Three", "Four", "Five", "Six",
                             "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                             "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

public:
    string
    numberToWords(int num)
    {

        if (num == 0)
            return "Zero";
        string res;
        int i = 0;
        while (num > 0)
        {
            int threeDigit = num % 1000;
            string cur = numberToWord0to1000(threeDigit);
            if (i > 0 && cur != "")
                cur += " " + names[i];
            num = num / 1000;
            if (res == "")
                res = cur;
            else
                res = cur + " " + res;
            i++;
        }
        string result = "";
        result += res[0];
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == ' ' && res[i - 1] == ' ')
                continue;
            result += res[i];
        }
        return result;
    }

    string numberToWord0to1000(int num)
    {
        if (num < 100)
            return numberToWord0To100(num);
        else
        {
            int h = num / 100;
            int d = num % 100;
            string res = numberToWord0To20(h) + " Hundred";
            if (d > 0)
                res += " " + numberToWord0To100(d);
            return res;
        }
    }

    string numberToWord0To100(int num)
    {
        if (num <= 20)
            return numberToWord0To20(num);
        else
        {
            int t = num / 10;
            int d = num % 10;
            string res = tens[t];
            if (d > 0)
                res += " " + numberToWord0To20(d);
            return res;
        }
    }

    string numberToWord0To20(int num)
    {
        return digits[num];
    }
};