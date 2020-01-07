#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<pair<int,int>,int>,int> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        return checkInterleave(s1,s2,s3,0,0,0);
    }

    bool checkInterleave(const string& s1,const string& s2,const string& s3, int i1,int i2,int i3) {
        if(s1.size()==i1 && s2.size()==i2 && s3.size()==i3){
            return true;
        }
        pair<int,int> conpair;
        conpair.first=i1;
        conpair.second=i2;
        pair<pair<int,int>,int> constractor_result_pair;
        constractor_result_pair.first=conpair;
        constractor_result_pair.second=i3;
        if(dp[constractor_result_pair]!=0){
            return dp[constractor_result_pair]==1;
        }
        if(i1<s1.size() && s1[i1]==s3[i3] && checkInterleave(s1,s2,s3,i1+1,i2,i3+1)){
            dp[constractor_result_pair]=1;
            return true;
        }
        if(i2<s2.size() && s2[i2]==s3[i3] && checkInterleave(s1,s2,s3,i1,i2+1,i3+1)){
            dp[constractor_result_pair]=1;
            return true;
        }
        else{
            dp[constractor_result_pair]=-1;
            return false;
        }

    }
};

int main() {
    string s1="aabcc";
    string s2="dbbca", s3 = "aadbbbaccc";
    Solution s;
    cout<<s.isInterleave(s1,s2,s3)<<endl;
    return 0;

}