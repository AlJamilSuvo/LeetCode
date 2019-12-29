#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> unique_char_map;
        for(int i=0;i<t.size();i++){
            unique_char_map[t.at(i)]++;
        }
        int unique_char_cnt=0;
        for(map<char,int>::iterator it=unique_char_map.begin();it!=unique_char_map.end();++it){
            unique_char_cnt+=it->second;
        }
        int required=unique_char_cnt;
        int left=0;
        int right=0;
        int min_length=-1;
        int min_length_left=-1;
        int found_in_window=0;
        map<char,int> window_char_map;
        while (right<s.size()){
            char a=s.at(right);
            if(unique_char_map[a]>0){
                window_char_map[a]++;
            }
            found_in_window=0;
            for(map<char,int>::iterator it=window_char_map.begin();it!=window_char_map.end();++it){
               found_in_window+=min(it->second,unique_char_map[it->first]);
            }
            if(found_in_window==required){
                while (left<right)
                {
                    char b=s.at(left);
                    if(unique_char_map[b]!=0 && window_char_map[b]==unique_char_map[b]) break;
                    else {
                        left++;
                        window_char_map[b]-=window_char_map[b]==0?0:1;
                    }
                }
                if(min_length==-1 or right-left<min_length){
                    min_length=right-left+1;
                    min_length_left=left;
                }
                window_char_map[s.at(left)]-=1;
                left++;
            }
            right++;


        }
        if(min_length!=-1) return s.substr(min_length_left,min_length);
        else return "";
    
    }
};

int main(){
    Solution sol;
    // string s;
    // string t;
    // cin>>s>>t;
    cout<<sol.minWindow("ADOBECODEBANC","AABC")<<endl;
    // return main();
}