#include <bits/stdc++.h>
using namespace std;

class Solution {
    map<pair<string,string>,int> dp;
public:
    int minDistance(string word1, string word2) {
        if (word1.size()==0 || word2.size()==0) {
            int distance=word1.size()-word2.size();
            if(distance<0) distance=-distance;
            return distance;
        }  
        if(word1==word2){
            return 0;
        }
        pair<string,string> pr;
        pr.first=word1;
        pr.second=word2;
        if(dp[pr]!=0){
            return dp[pr];
        }
        if(word1[0]==word2[0]){
            return minDistance(word1.substr(1,word1.size()),word2.substr(1,word2.size()));
        }
        else{
            int del_dis=minDistance(word1.substr(1,word1.size()),word2)+1;
            int ins_dis=minDistance(word1,word2.substr(1,word2.size()))+1;
            int rep_dis=minDistance(word1.substr(1,word1.size()),word2.substr(1,word2.size()))+1;
            int min_dis=min(del_dis,ins_dis);
            min_dis=min(min_dis,rep_dis);
            dp[pr]=min_dis;
            return min_dis;
        }

    }
};

int main(){
    string w1,w2;
    cin>>w1>>w2;
    Solution s;
    cout<<s.minDistance(w1,w2)<<endl;
}

/*
"dinitrophenylhydrazine"
"acetylphenylhydrazine"


*/