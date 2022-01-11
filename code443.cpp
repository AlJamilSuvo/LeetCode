#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int compress(vector<char> &chars)
//     {

//         int char_count = 0;
//         char prevChar;
//         vector<char> newVector;
//         for (auto ch : chars)
//         {
//             if (ch == prevChar)
//             {
//                 char_count += 1;
//             }
//             else
//             {

//                 if (char_count > 1)
//                 {
//                     auto cnt_str = to_string(char_count);
//                     for (auto cnt_ch : cnt_str)
//                         newVector.push_back(cnt_ch);
//                 }
//                 cout << ch << endl;
//                 char_count = 1;
//                 newVector.push_back(ch);
//                 prevChar = ch;
//             }
//         }
//         if (char_count > 1)
//         {
//             auto cnt_str = to_string(char_count);
//             for (auto cnt_ch : cnt_str)
//                 newVector.push_back(cnt_ch);
//         }
//         chars = newVector;
//         return chars.size();
//     }
// };

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int result_len = 0;
        int current_position = 0;
        int len = chars.size();
        while (current_position < len)
        {
            chars[result_len] = chars[current_position];
            current_position += 1;
            int count = 1;
            while (current_position < len && chars[current_position] == chars[result_len])
            {
                count += 1;
                current_position += 1;
            }
            result_len += 1;
            if (count > 1)
            {
                result_len += ceil(log10(count+1));
                int i = 1;
                while (count > 0)
                {
                    chars[result_len - i] = '0' + count % 10;
                    i += 1;
                    count = count / 10;
                }
            }
        }
        return result_len;
    }
};

int main()
{
    vector<char> in1 = {'a', 'a', 'b', 'b', 'c', 'c'};
    Solution s;
    s.compress(in1);
    for (auto ch : in1)
    {
        cout << ch << " ";
    }
    cout << endl;
}