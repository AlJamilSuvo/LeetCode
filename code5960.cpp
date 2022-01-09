#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        int wordStartIndex = 0;
        bool was_last_char_space = true;
        for (int currentIndex = 0; currentIndex < title.size(); currentIndex++)
        {
            if (title[currentIndex] == ' ')
            {
                was_last_char_space = true;
                continue;
            }
            if (was_last_char_space)
            {
                wordStartIndex = currentIndex;
                was_last_char_space = false;
            }
            title[currentIndex] = tolower(title[currentIndex]);
            if (currentIndex - wordStartIndex == 2)
            {
                title[wordStartIndex] = toupper(title[wordStartIndex]);
            }
        }
        return title;
    }
};


int main(){
    Solution s;
    cout<<s.capitalizeTitle("capiTalIze tHe titLe")<<endl;
    cout<<s.capitalizeTitle("First leTTeR of EACH Word")<<endl;
    cout<<s.capitalizeTitle("i lOve leetcode")<<endl;
}